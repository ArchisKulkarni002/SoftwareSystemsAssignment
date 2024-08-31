/*
============================================================================
Name : 17a.c
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

	//create a ticket
	struct ticket t1;
	t1.number=15;
	printf("\ncurrent ticket number: %d", t1.number);

	//write the struct to the file
	int status=write(fd, (char*)&t1, sizeof(struct ticket));
	if(status==-1){printf("\nwriting to file failed.");}

	close(fd);
}

/* ./create.o

current ticket number: 15 */