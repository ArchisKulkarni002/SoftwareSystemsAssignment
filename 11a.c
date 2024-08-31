/*
============================================================================
Name : 11a.c
Author : Archis Kulkarni
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
a. use dup 
b. use dup2 
c. use fcntl
Date: 13-08-2024
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>

int main(){

	char message1[] = {"Hello there from F1\n"};
	char message2[] = {"Hello there from F2\n"};
	
	int fd1=open("sampleFile", O_RDWR | O_APPEND);

	int fd2=dup(fd1);

	write(fd1, message1, sizeof(message1));
	write(fd2, message2, sizeof(message2));

	close(fd1);
	close(fd2);
}
