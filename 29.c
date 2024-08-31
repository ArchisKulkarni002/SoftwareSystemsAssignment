/*
============================================================================
Name : 29.c
Author : Archis Kulkarni
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR). 
Date: 29-08-2024
============================================================================
*/
#include<stdio.h>
#include<sched.h>
#include<unistd.h>
#include<errno.h>

int main(){

    //print current scheduler
    printf("Current scheduling policy: %d\n", sched_getscheduler(getpid()));
    printf("Changing policy to: %d\n", SCHED_FIFO);

    //set the scheduler param with priority
    struct sched_param param;
    param.sched_priority = 10;

    // change the priority and print success or error
    int ret=sched_setscheduler(0, SCHED_FIFO,&param);
    if(ret!=0){printf("Some error occoured: %d\n", errno);}
    printf("Current scheduling policy: %d\n", sched_getscheduler(getpid()));

}   

/* sudo assignment29/a.out
[sudo] password for linuxboi:
Current scheduling policy: 0
Changing policy to: 1
Current scheduling policy: 1 */