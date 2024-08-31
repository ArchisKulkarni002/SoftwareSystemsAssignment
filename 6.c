/*
============================================================================
Name : 6.c
Author : Archis Kulkarni
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 12-08-2024
============================================================================
*/
#include<unistd.h>

int main(){
	// first create buffer
	int count = 2048;
	char buffer[count];

	// read from stdin to buffer
	ssize_t bytesRead=read(0, &buffer, count);

	// write the contents to stdout, we use bytes read amount of bytes to print instead of whole buffer
	if(bytesRead>0){
		ssize_t status1 = write(1, &buffer, bytesRead);
		
	}
}

/*  ./a.out
Hello there good morning!
Hello there good morning! */