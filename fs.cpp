//
// Created by Bartosz Cybulski on 12.01.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>

#define FILE_SIZE 2048
#define MAX_FILE_NAME 14

char* FileName;
int FileID = -1;

typedef struct inode
{
    char fileName[MAX_FILE_NAME];
    unsigned long fileBegin;
    unsigned long fileSize;
    unsigned long nextNode;
};

void makeDisk(){
    unsigned buff[FILE_SIZE];

    for(int i = 0 ; i < FILE_SIZE ; i++){
        buff[i]='\0';
    }

    FileID = creat(FileName, 0666);
    if(FileID < 0)
    {
        fprintf(stderr,"Creating errpr\n");
        exit(-1);
    }
    else
        fprintf(stdout,"Virtual Disk was created\n");
    write(FileID, buff, FILE_SIZE);
    close(FileID);
    FileID=open(FileName, O_RDWR);
}

void openDisk(){
    FileID = open(FileName, O_RDWR);
    if(FileID < 0)
    {
        fprintf(stderr,"Opening error\n");
        exit(-1);
    }
}
void removeDisk(){
    close(FileID);
    int i = remove(FileName);
    if(i)
        fprintf(stderr,"Removing error\n");
    exit(i);
}

void closeDisk(){
    close(FileID);
    exit(0);
}

char* unsignedToChar