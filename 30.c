/*
============================================================================
Name : 30.c
Author : Archis Kulkarni
Description :  Write a program to run a script at a specific time using a Daemon process.
Date: 30-08-2024
============================================================================
*/
#include<stdio.h>
#include<sched.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

    pid_t pid;

    // Fork the process to create a new child
    pid = fork();
    if (pid > 0) {
        // Parent process exits
        exit(0);
    }

    //we create new session 
    if (setsid() < 0) {
        perror("setsid");
        exit(0);
    }

    // we fork again to ensure that the daemon cannot acquire a controlling terminal
    pid = fork();
    if (pid > 0) {
        // Parent process exits
        exit(0);
    }

    // then set umask to 0 to make sure permissions are set correctly
    umask(0);

    // change the working directory to the root
    chdir("/") < 0;

    // close standard file descriptors
    close(0);
    close(1);
    close(2);

    // open /dev/null as stdin, stdout, stderr
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_RDWR);  
    open("/dev/null", O_RDWR);  
    
    // we sleep 1 sec and wait for 10 secs to run ls command in the background.
    int counter=0;
    while (1)
    {
        sleep(1);
        counter++;
        if (counter>10)
        {
            execl("/bin/ls", "ls", (char *)NULL);
        }
        
    }
    printf("There was error for executing daemon.\n");

}   