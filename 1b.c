/*
============================================================================
Name : 1b.c
Author : Archis Kulkarni
Description : Create the following types of a files using (i) shell command (ii) system call 
a. soft link (symlink system call) 
b. hard link (link system call) 
c. FIFO (mkfifo Library Function or mknod system call)
Date: 11-08-2024
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int status = link("trialFile","hardlinkFileSyscall");
	if(status==-1){
		perror("hard link creation failed");
	}
	printf("hard link created.");
}

/* ./b.out
hard link created. */