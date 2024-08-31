/*
============================================================================
Name : 3.c
Author : Archis Kulkarni
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call 
Date: 12-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	// lets first define a mode to create the file with
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	
	// lets create the file and obtain descriptor
	int fileDescriptor = creat("createdFile.txt", mode);
	printf("File created with a descriptor: %d", fileDescriptor);

	return 0;
}

/* ./a.out
File created with a descriptor: 3 */