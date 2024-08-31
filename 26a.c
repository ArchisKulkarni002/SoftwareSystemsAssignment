/*
============================================================================
Name : 26a.c
Author : Archis Kulkarni
Description : Write a program to execute an executable program. 
a. use some executable program 
b. pass some input to an executable program. (for example execute an executable of $./a.out name) 
Date: 28-08-2024
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

    int ret;
    printf("Running program 25.out\n\n");
    ret = execl("./25.out", "25.out", (char *)NULL);
    printf("\nProgram 25.out terminated\n");
}

/* /a.out
Running program 25.out

This is child process: 203616
Inside parent process. Waiting for child process 203617
This is child process: 203618
This is child process: 203617
Child 203617 exited normally. */