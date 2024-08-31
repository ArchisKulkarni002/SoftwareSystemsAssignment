/*
============================================================================
Name : 17b.c
Author : Archis Kulkarni
Description : Write a program to simulate online ticket reservation.  Implement write lock  
Write a program to open a file, store a ticket number and exit.  Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file. 
Date: 20-08-2024
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
	struct flock lock={F_WRLCK, SEEK_SET,0,0};
	int status=fcntl(fd,F_SETLKW, &lock);
	if(status==-1){printf("\nError acquiring lock");}
	else{printf("\nWrite lock acquired");}

	//create ticket object
	struct ticket t1;

	//read the file and load the ticket
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
	struct flock lock1={F_UNLCK, SEEK_SET,0,0};
	int status1=fcntl(fd,F_SETLK, &lock1);
	if(status==-1){printf("\nError removing lock");}
	else{printf("\nWrite lock removed");}

	close(fd);
}

/* ./update.o

Write lock acquired
current ticket number: 15
overwritten ticket number: 17
Write lock removed */