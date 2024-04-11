#include <stdio.h>

char* username = "tom@smail.com";

void printUserName()
{
    printf("%s\n",username);
}

void resetUserName()
{
    username = "undefined";
}