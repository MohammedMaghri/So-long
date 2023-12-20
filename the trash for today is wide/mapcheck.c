#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mapchek.h"

int newlinechekc(char string)
{
    if (string == '\n')
        return (0) ;
    return (1);
}
int tothelinecount(char *string)
{
    int index ;

    index = 0;
    while (string[index] && string[index] != '\n')
    {
        index++ ;
    }
    index++ ;
    return index ;
}
int checkwithealllines(char *string ,int linetotal)
{
    int index ;
    int flag ;

    flag = 0 ;
    index = linetotal ;
    while (string[index])
    {
        flag++ ;
        index++ ;
        if (string[index] == '\n')
        {
            printf("%d\n" , flag);
            if (flag != linetotal)
            {
                return (1);
            }
            flag = 0;
        }
    }
    return  (0);
}
int checkvalidmap(char *string)
{
    int index ;
    int firstlinelenght = tothelinecount(string);
    index = 0; 
    return firstlinelenght ;
}