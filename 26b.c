/*
============================================================================
Name : 26b.c
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
    const char arg1[] = {"a.out"};
    printf("Running program 14.out with string %s\n\n", arg1);
    ret = execl("./14.out", "14.out", arg1,(char *)NULL);
    printf("\nProgram 14.out terminated\n");
}

/* ./b.out
Running program 14.out with string a.out

Inode number is: 51661
This is a regular file. */