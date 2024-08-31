/*
============================================================================
Name : 4.c
Author : Archis Kulkarni
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 20-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	// lets first define flags to open the file with
	int flags = O_RDWR|O_CREAT|O_EXCL;
	
	// lets open the file and obtain descriptor. this wont create a file if not exist
	int fileDescriptor = open("createdFile", flags);
	if (fileDescriptor == -1){
		printf("Failed to open");
		return 0;
	}
	printf("File opened with a descriptor: %d", fileDescriptor);

	return 0;
}

/* ./a.out
File opened with a descriptor: 3 */