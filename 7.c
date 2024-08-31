/*
============================================================================
Name : 7.c
Author : Archis Kulkarni
Description : Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 27-08-2024
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int fd1, fd2;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];


    // Open the file for reading
    fd1 = open("file1", O_RDONLY);

    // open the destination file for writing
    fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // copy the contents of the file1 to the file2
    while ((bytes_read = read(fd1, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(fd2, buffer, bytes_read);
    }


    // close both files
    close(fd1);
    close(fd2);

    return 0;
}

