/*
============================================================================
Name : 20.c
Author : Archis Kulkarni
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 28-08-2024
============================================================================
*/
#include<sys/resource.h>
#include<stdio.h>

int main(){

    // we use getpriority system call for getting the nice value of current running program
    int priority = getpriority(PRIO_PROCESS, 0);
    printf("Priority of the process is: %d\n", priority);

    while(1){}
}

/* ./a.out
Priority of the process is: 0

201052 linuxboi  20   0    2776    928    840 R 100.0   0.0   0:53.46

renice -n 2 -p 201052
201052 (process ID) old priority 0, new priority 2

201052 linuxboi  22   2    2776    928    840 R 100.0   0.0   2:20.29 */