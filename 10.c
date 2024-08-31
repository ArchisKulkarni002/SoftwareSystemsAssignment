/*
============================================================================
Name : 10.c
Author : Archis Kulkarni
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes.  
a. check the return value of lseek 
b. open the file with od and check the empty spaces in between the data.
Date: 13-08-2024
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>

int main(){

	// open the file, declare a buffer of memory
	int fd=open("samplefile", O_RDWR);
	char buffer[2048];

	//write some characters in the buffer
	for(int i=0;i<10;i++){
		buffer[i]='a';
	}

	// write the contents of buffer to file
	ssize_t fileRead=write(fd, &buffer, 10);

	//use lseek to go ahead 10 chars and print the sequence again
	off_t offsetReturn=lseek(fd, 10, SEEK_CUR);

	fileRead=write(fd, &buffer, 10);
}
