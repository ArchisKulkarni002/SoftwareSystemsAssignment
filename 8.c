/*
============================================================================
Name : 8.c
Author : Archis Kulkarni
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.
Date: 27-08-2024
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	// first create buffer
	int count = 2048;
	char buffer[count], line[count];
	int line_index=0;

	// first we open the file
	int fileDescriptor=open("sampleText", O_RDONLY);

	// read from file to buffer
	ssize_t bytesRead;

	while(bytesRead=read(fileDescriptor, &buffer, count)){
		for (ssize_t i = 0; i < count; i++)
		{
			if (buffer[i] == '\n') {
                line[line_index] = '\0'; 
                printf("%s\n", line);    
                line_index = 0;          
            } else {
                line[line_index++] = buffer[i];
                if (line_index >= sizeof(line) - 1) {
                    printf("Line too long\n");
                    close(fileDescriptor);
                    return 1;
                }
            }
		}
		
	}


	// close the fileDescriptor
	close(fileDescriptor);
}


/* ./a.out
Lorem Ipsum is simply dummy text of the printing and typesetting industry.
India is my country!
All Indians are my brothers and sisters!


 */