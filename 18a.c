/*
============================================================================
Name : 18a.c
Author : Archis Kulkarni
Description : Write a program to perform Record locking. 
a. Implement write lock 
b. Implement read lock 
Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
to avoid race condition. 
Date: 30-08-2024
============================================================================
*/
#include<fcntl.h>
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	//open a file
	int fd=open("tickets", O_RDWR);
	struct ticket{
		int number;
	};

	//lock the file
	struct flock lock={F_WRLCK, SEEK_SET,sizeof(struct ticket),sizeof(struct ticket)};
	int status=fcntl(fd,F_SETLKW, &lock);
	if(status==-1){printf("\nError acquiring lock");}
	else{printf("\nWrite lock acquired");}

	//create ticket object
	struct ticket t1;

	//read the file and load the ticket
	lseek(fd, sizeof(struct ticket), SEEK_SET);
	read(fd, &t1, sizeof(struct ticket));
	printf("\ncurrent ticket number: %d",t1.number);
	t1.number+=2;

	//set cursor back
	lseek(fd, -1*sizeof(struct ticket), SEEK_CUR);

	//write it back
	int statusw=write(fd, (char*)&t1, sizeof(struct ticket));
	if(statusw==-1){printf("\nwriting to file failed");}
	else{printf("\noverwritten ticket number: %d",t1.number);}

	//unlock file
	struct flock lock1={F_UNLCK, SEEK_SET,sizeof(struct ticket),sizeof(struct ticket)};
	int status1=fcntl(fd,F_SETLK, &lock1);
	if(status==-1){printf("\nError removing lock");}
	else{printf("\nWrite lock removed");}

	close(fd);
}

/* 8$ ./a.out

Write lock acquired
current ticket number: 16
overwritten ticket number: 18
Write lock removed */