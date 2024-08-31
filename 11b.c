/*
============================================================================
Name : 11b.c
Author : Archis Kulkarni
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
a. use dup 
b. use dup2 
c. use fcntl
Date: 17-08-2024
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>

int main(){

	//create messages and new file desc id
	char message1[] = {"Hello there from FD1\n"};
	char message2[] = {"Hello there from FD2\n"};
	int newfd = 10;
	//open a file
	int fd1=open("sampleFile1", O_RDWR | O_APPEND);
	//duplicate the fd
	int fd2=dup2(fd1,newfd);
	//write message1 and 2 seperately, it gets into same file
	write(fd1, message1, sizeof(message1));
	write(fd2, message2, sizeof(message2));
	//close the descriptors
	close(fd1);
	close(fd2);
}
