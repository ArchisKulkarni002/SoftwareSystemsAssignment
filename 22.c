/*
============================================================================
Name : 22.c
Author : Archis Kulkarni
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file. 
Date: 30-08-2024
============================================================================
*/
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

    // we open a file
    int fd = open("sampletext", O_RDWR);
    char childmessage[] = {"This is message from child."};
    char parentmessage[] = {"This is message from parent."};

    
    // we fork the process and create a new child process, 
    int ret=fork();

    // then we write the child and parent process ids
    if (ret==0)
    {
        write(fd, &childmessage, sizeof(childmessage));
    }else if (ret>0)
    {
        write(fd, &parentmessage, sizeof(parentmessage));
    }
}
    
/* cat assignment22/sampletext
This is message from parent.This is message from child. */    
    
    