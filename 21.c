/*
============================================================================
Name : 21.c
Author : Archis Kulkarni
Description : Write a program, call fork and print the parent and child process id.
Date: 30-08-2024
============================================================================
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    
    // we fork the process and create a new child process, 
    pid_t pid=fork();

    // then we write the child and parent process ids

    // child process
    if(pid==0){printf("Child process id: %d\n", getpid());}

    // parent process
    else if(pid>0){printf("Parent process id: %d\n", getpid());}
       
}

/* ./a.out
Parent process id: 355
Child process id: 354 */