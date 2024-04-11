#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/file_printer.h"


static int getFileLength(FILE* fp)
{
    fseek(fp,0,SEEK_END);
    int file_length = ftell(fp);
    return file_length;
}

static void readFile(FILE* fp,char* buffer, int file_legth)
{
    fseek(fp,0,SEEK_SET);
    int read_elemts = fread(buffer,1,file_legth,fp);
    buffer[read_elemts] = '\0';

}

void printFile(char* filename)
{
    FILE* fp = 0;
    char* text = 0;

    assert(filename && "invalid file name\n");


    fp = fopen(filename,"r");
    assert(fp && "unable to open file\n");

    int file_length = getFileLength(fp);

    if(file_length>0)
    {
        text = malloc(file_length);
        if(text)
        {
            readFile(fp,text,file_length);
            printf("%s\n",text);

            free(text);
            text = 0;
        }
    }
        fclose(fp);
        fp = 0;
}
int main();