/*
============================================================================
Name : 27a.c
Author : Archis Kulkarni
Description : Write a program to execute ls -Rl by the following system calls 
a. execl 
b. execlp 
c. execle 
d. execv 
e. execvp
Date: 29-08-2024
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

    int ret;
    const char arg1[] = {"-Rl"};
    printf("Running ls -Rl %s\n\n", arg1);
    ret = execl("/bin/ls", "ls", arg1,(char *)NULL);
}

/* ./a.out
Running ls -Rl -Rl

.:
total 100
-rw-r--r-- 1 linuxboi linuxboi   203 Aug 29 13:56 27a.c
-rw-r--r-- 1 linuxboi linuxboi   190 Aug 29 14:01 27b.c
-rw-r--r-- 1 linuxboi linuxboi   268 Aug 29 14:06 27c.c
-rw-r--r-- 1 linuxboi linuxboi   229 Aug 29 14:09 27d.c
-rw-r--r-- 1 linuxboi linuxboi   225 Aug 29 14:11 27e.c
-rwxr-xr-x 1 linuxboi linuxboi 16064 Aug 29 13:57 a.out
-rwxr-xr-x 1 linuxboi linuxboi 16064 Aug 29 14:01 b.out
-rwxr-xr-x 1 linuxboi linuxboi 16064 Aug 29 14:06 c.out
-rwxr-xr-x 1 linuxboi linuxboi 16064 Aug 29 14:09 d.out
-rwxr-xr-x 1 linuxboi linuxboi 16064 Aug 29 14:11 e.out */