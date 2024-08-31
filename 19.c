/*
============================================================================
Name : 19.c
Author : Archis Kulkarni
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30-08-2024
============================================================================
*/
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

unsigned long long getTime(){
	unsigned long long dst;
     __asm__ __volatile__ ("rdtsc":"=A" (dst));
     return dst; 
}

int main(){
	time_t time1=getTime();
	pid_t pid=getpid();
	time_t time2=getTime();

	double cpuspeed = 3.0e6;
	long double timeval = (time2-time1)/cpuspeed;

	printf("pid: %d\n", pid);
	printf("cpu cycles taken by pid: %ld\n", (time2-time1));
	printf("miliseconds taken by pid: %Lf\n", timeval);
}

/* ./a.out
pid: 200866
cpu cycles taken by pid: 13791
miliseconds taken by pid: 0.004597 */