/*
============================================================================
Name : 28.c
Author : Archis Kulkarni
Description : Write a program to get maximum and minimum real time priority.
Date: 29-08-2024
============================================================================
*/
#include<stdio.h>
#include<sched.h>

int main(){

    printf("Maximum priority for realtime: %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("Minimum priority for realtime: %d\n", sched_get_priority_min(SCHED_FIFO));
    
    printf("Maximum priority for round robin: %d\n", sched_get_priority_max(SCHED_RR));
    printf("Minimum priority for round robin: %d\n", sched_get_priority_min(SCHED_RR));
}

/* a.out
Maximum priority for realtime: 99
Minimum priority for realtime: 1
Maximum priority for round robin: 99
Minimum priority for round robin: 1 */