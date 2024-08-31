/*
============================================================================
Name : 1a.c
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
	int status = symlink("trialFile","softlinkFileSyscall");
	if(status==-1){
		perror("soft link creation failed");
	}
	printf("symbolic link created.");
}

/* symbolic link created. */
