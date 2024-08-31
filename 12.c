/*
============================================================================
Name : 12.c
Author : Archis Kulkarni
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 17-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>

int main(){
	int fd=open("samplefile", O_RDWR);
	int returnedValue=fcntl(fd,F_GETFL);

	printf("The returned value for file opening flag is: %d", returnedValue);
	
}

/* ./a.out
The returned value for file opening flag is: 32770 */