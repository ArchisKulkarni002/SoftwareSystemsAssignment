/*
============================================================================
Name : 16a.c
Author : Archis Kulkarni
Description : Write a program to perform mandatory locking. 
a. Implement write lock 
b. Implement read lock
Date: 20-08-2024
============================================================================
*/
#include<fcntl.h>
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	//open a file
	int fd=open("samplefile", O_RDWR);
	//we add write lock on the fd
	struct flock lock={F_WRLCK, SEEK_SET, 0,0};
	//if lock fails print error
	int status=fcntl(fd, F_SETLKW, &lock);
	if(status==-1){printf("Error while acquiring lock");}
	else{printf("Write lock acquired");}
	//keep the file locked till user input
	getchar();

	//release lock
	struct flock unlock={F_UNLCK, SEEK_SET, 0,0};
	int status1=fcntl(fd, F_SETLK, &unlock);
	if(status1==-1){printf("Error while removing lock");}
	else{printf("Write lock removed");}
	close(fd);
}

/* ./read.out
Read lock acquired

./write.out

./read.out
Read lock acquireds
Read lock removed

./write.out
Write lock acquired */