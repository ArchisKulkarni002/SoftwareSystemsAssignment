/*
============================================================================
Name : 23.c
Author : Archis Kulkarni
Description :  Write a program to create a Zombie state of the running program.
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

    // child process exits after printing
    if(pid==0){
        printf("Child process id: %d exiting now\n", getpid());
        exit(0);
    }

    // parent process gets blocked for io, creating zombie for child
    else if(pid>0){
        printf("Parent process id: %d\n", getpid());
        getchar();
    }
       
}

/* a.out
Parent process id: 202506
Child process id: 202507 exiting now

linuxboi  202507  0.0  0.0      0     0 pts/0    Z+   10:15   0:00 [a.out] < */