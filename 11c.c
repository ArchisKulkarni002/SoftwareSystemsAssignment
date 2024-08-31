/*
============================================================================
Name : 11c.c
Author : Archis Kulkarni
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
a. use dup 
b. use dup2 
c. use fcntl
Date: 30-08-2024
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int fd1, fd2;
    const char *filename = "sampleFile";
    fd1 = open(filename, O_RDONLY);

    // Duplicate the file descriptor using fcntl
    fd2 = fcntl(fd1, F_DUPFD); // 100 is the minimum value for the new file descriptor

    printf("Original file descriptor: %d\n", fd1);
    printf("New file descriptor: %d\n", fd2);

}
