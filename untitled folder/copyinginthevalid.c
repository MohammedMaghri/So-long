#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mapchek.h"
#include <fcntl.h>
int lencount(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
char *makestringopy(char *string)
{
    int index = 0 ;
    char *alloca ;
    alloca = malloc(sizeof(string) * lencount(string) + 1);
    while (string[index])
    {
        alloca[index] = string[index] ;
        index++ ;
    }
    alloca[index] = '\0';
    return alloca ;
}
char *copyofthestringuse(char *string, int maxlenght)
{
    int index = 0 ;
    char *allocaiton ;
    allocaiton = malloc(sizeof(char) * maxlenght + 1);
    while (string[index] && index <= maxlenght)
    {
        allocaiton[index] = string[index] ;
        index++ ;
    }
    allocaiton[index] = '\0';
    return allocaiton ;
}
int countnewline(char *string)
{
    int index  = 0;
    int flag = 0;
    while (string[index])
    {
        if (string[index] == '\n')
            flag++ ;
        index++ ;
    }
    return flag + 1;
}
char **stringreturn(char *string)
{
    int index = 0 ;
    char **allocation ;
    int i = 0 ;
    int checkpoint = 0;
    allocation = malloc(sizeof(char **) * (countnewline(string) + 1));
    while (string[index])
    {
        if (string[index] == '\n')
        {
            checkpoint = index ;
            index++ ;
            checkpoint--;
            allocation[i] = copyofthestringuse(string ,checkpoint);
            string = makestringopy(&string[index]);
            index = 0;
            i++ ;
        }
        index++ ;
    }
    allocation[i] = makestringopy(string);
    i++ ;
    allocation[i] = NULL ;
    return allocation ;
}
