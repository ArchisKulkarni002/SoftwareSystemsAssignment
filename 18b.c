/*
============================================================================
Name : 18b.c
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
	struct flock lock={F_RDLCK, SEEK_SET,sizeof(struct ticket),sizeof(struct ticket)};
	int status=fcntl(fd,F_SETLKW, &lock);
	if(status==-1){printf("\nError acquiring lock");}
	else{printf("\nRead lock acquired");}

	//create ticket object
	struct ticket t1;

	//read the file and load the ticket
	lseek(fd, sizeof(struct ticket), SEEK_SET);
	read(fd, &t1, sizeof(struct ticket));
	printf("\ncurrent ticket number: %d",t1.number);

	//pause the program
	getchar();

	//unlock file
	struct flock lock1={F_UNLCK, SEEK_SET,sizeof(struct ticket),sizeof(struct ticket)};
	int status1=fcntl(fd,F_SETLK, &lock1);
	if(status==-1){printf("\nError removing lock");}
	else{printf("\nRead lock removed");}

	close(fd);
}

/* ./b.out

Read lock acquired
current ticket number: 18

Read lock removed */