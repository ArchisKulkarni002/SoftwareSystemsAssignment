/*
============================================================================
Name : 14ab.c
Author : Archis Kulkarni
Description :  Write a program to find the type of a file. 
a. Input should be taken from command line. 
b. program should be able to identify any type of a file.
Date: 28-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	// create stat strcut object
    struct stat s1;

    //find the filename from program arguments and pass to stat function
    int status=lstat(argv[1], &s1);
    if(status==-1){printf("Something went wrong!"); return 0;}

    //retrieve the inode number and type using st_mode variable in the stat struct
    // we can use the built in macros for the same
    printf("Inode number is: %ld\n",s1.st_ino);

    if(S_ISREG(s1.st_mode)){printf("This is a regular file.\n");}
    if(S_ISDIR(s1.st_mode)){printf("This is a directory.\n");}
    if(S_ISCHR(s1.st_mode)){printf("This is a character device.\n");}
    if(S_ISBLK(s1.st_mode)){printf("This is a block device.\n");}
    if(S_ISFIFO(s1.st_mode)){printf("This is a fifo named pipe.\n");}
    if(S_ISLNK(s1.st_mode)){printf("This is a symbolic link.\n");}
    if(S_ISSOCK(s1.st_mode)){printf("This is a socket file.\n");}

	return 0;
}

/* ./a.out 14.out
Inode number is: 51667
This is a regular file. */