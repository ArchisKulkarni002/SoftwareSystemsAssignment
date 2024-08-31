/*
============================================================================
Name : 13.c
Author : Archis Kulkarni
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 17-08-2024
============================================================================
*/
#include<stdio.h>
#include<sys/select.h>

int main(){

	//declare read fd set
	fd_set readfs;
	//remove all fds from sets and add readfs to it
	FD_ZERO(&readfs);
	FD_SET(0,&readfs);

	//declare time interval
	struct timeval timeout;
	timeout.tv_sec=10;
	timeout.tv_usec=0;

	//perform select call
	int returnvalue=select(1,&readfs,NULL,NULL,&timeout);
	//print messages based on returned value
	if(returnvalue==0){printf("Timeout reached! Try again.");}
	else if(returnvalue==-1){printf("There was an error! Try again.");}
	else{printf("%d file descriptors were modified.",returnvalue);}
}

/* ./a.out
asd
1 file descriptors were modified. */