/*
============================================================================
Name : 25.c
Author : Archis Kulkarni
Description : Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).
Date: 28-08-2024
============================================================================
*/
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    pid_t pid[3], ret;
    int status;
    // we fork the process and create a new child process, 
    for (int i = 0; i < 3; i++)
    {
        pid[i] = fork();
        
        //child process
        if (pid[i]==0)
        {
            printf("This is child process: %d\n", getpid());   
            exit(0);         
        }  
    }

    printf("Inside parent process. Waiting for child process %d\n", pid[1]);
    ret=waitpid(pid[1], &status,0);
    if (WIFEXITED(status))
    {
        printf("Child %d exited normally.\n", pid[1]);
    }
}

/* a.out
This is child process: 203016
This is child process: 203015
Inside parent process. Waiting for child process 203016
Child 203016 exited normally.
This is child process: 203017 */