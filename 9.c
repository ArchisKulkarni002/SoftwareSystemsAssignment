/*
============================================================================
Name : 9.c
Author : Archis Kulkarni
Description : Write a program to print the following information about a given file. 
a. inode 
b. number of hard links 
c. uid 
d. gid 
e. size 
f. block size 
g. number of blocks 
h. time of last access 
i. time of last modification 
j. time of last change 
Date: 28-08-2024
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	// create stat strcut object
    struct stat s1;

    //find the filename from program arguments and pass to stat function
    int status=lstat("a.out", &s1);
    if(status==-1){printf("Something went wrong!"); return 0;}

    //retrieve the variables in the stat struct
    printf("Inode number is: %ld\n",s1.st_ino);
    printf("No of hard links is: %ld\n",s1.st_nlink);
    printf("UID is: %d\n",s1.st_uid);
    printf("GID is: %d\n",s1.st_gid);
    printf("Size is: %ld\n",s1.st_size);
    printf("Block size is: %ld\n",s1.st_blksize);
    printf("No of blocks is: %ld\n",s1.st_blocks);
    printf("Time of last access is: %ld\n",s1.st_atime);
    printf("Time of last modification is: %ld\n",s1.st_mtime);
    printf("Time of last change is: %ld\n",s1.st_ctime);


	return 0;
}


/*  ./a.out
Inode number is: 51742
No of hard links is: 1
UID is: 1000
GID is: 1000
Size is: 16048
Block size is: 4096
No of blocks is: 32
Time of last access is: 1725014883
Time of last modification is: 1725014882
Time of last change is: 1725014882 */