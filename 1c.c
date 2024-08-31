/*
============================================================================
Name : 1c.c
Author : Archis Kulkarni
Description : Create the following types of a files using (i) shell command (ii) system call 
a. soft link (symlink system call) 
b. hard link (link system call) 
c. FIFO (mkfifo Library Function or mknod system call)
Date: 30-08-2024
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int status = mknod("somefile",S_IFIFO|S_IRWXU, 0);
	if(status==-1){
		perror("fifo creation failed");
	}
	printf("fifo created.");
}


/* ./c.out
fifo created. */