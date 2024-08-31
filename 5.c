/*
============================================================================
Name : 5.c
Author : Archis Kulkarni
Description :  Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd.
Date: 26-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	// lets first define a mode to create the file with
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	
	// lets create the file and obtain descriptor
	int fileDescriptor1 = creat("createdFile1.txt", mode);
	int fileDescriptor2 = creat("createdFile2.txt", mode);
	int fileDescriptor3 = creat("createdFile3.txt", mode);
	int fileDescriptor4 = creat("createdFile4.txt", mode);
	int fileDescriptor5 = creat("createdFile5.txt", mode);
	printf("Files created with a descriptor: %d", fileDescriptor1);
	printf("Files created with a descriptor: %d", fileDescriptor2);
	printf("Files created with a descriptor: %d", fileDescriptor3);
	printf("Files created with a descriptor: %d", fileDescriptor4);
	printf("Files created with a descriptor: %d", fileDescriptor5);
    while(1){

    }

	return 0;
}

/* ls /proc/196670/fd
0  1  2  3  4  5  6  7 */