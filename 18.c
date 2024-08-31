/*
============================================================================
Name : 18.c
Author : Archis Kulkarni
Description : Write a program to perform Record locking. 
a. Implement write lock 
b. Implement read lock 
Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
to avoid race condition. 
Date: 30-08-2024
============================================================================
*/
#include<fcntl.h>
#include<sys/file.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	// using this file for creating tickets file

	//open a file
	int fd=open("tickets", O_RDWR);
	struct ticket{
		int number;
	};

	//create a ticket
	struct ticket t1[3];
	t1[0].number=15;
	t1[1].number=16;
	t1[2].number=17;
	printf("\ncurrent ticket number1: %d", t1[0].number);
	printf("\ncurrent ticket number2: %d", t1[1].number);
	printf("\ncurrent ticket number3: %d", t1[2].number);

	//write the struct to the file
	int status=write(fd, (char*)t1, sizeof(struct ticket));
	int status1=write(fd, (char*)(t1+1), sizeof(struct ticket));
	int status2=write(fd, (char*)(t1+2), sizeof(struct ticket));
	if(status==-1 || status1==-1 || status2==-1){printf("\nwriting to file failed.");}

	close(fd);
}

/* ./create.out

current ticket number1: 15
current ticket number2: 16
current ticket number3: 17 */