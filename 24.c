/*
============================================================================
Name : 24.c
Author : Archis Kulkarni
Description : Write a program to create an orphan process. 
Date: 30-08-2024
============================================================================
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    
    // we fork the process and create a new child process, 
    pid_t pid=fork();

    // then we write the child and parent process ids

    // child process continues to be there for user ip
    if(pid==0){
        printf("Child process id: %d exiting now\n", getpid());
        getchar();
    }

    // parent process exits before child does, creating orphan
    else if(pid>0){
        printf("Parent process id: %d\n", getpid());
        exit(0);
    }
       
}