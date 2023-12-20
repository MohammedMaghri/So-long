#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int checkhowmany(char *string)
{
    int index ;
    int flag ;

    flag = 0;
    index = 0 ;

    while (string[index])
    {
        if (string[index] == '\n')
            flag++ ;
        index++ ;
    }
    return flag ;
}
char *fillfill(char *string , int position)
{
    int index ;
    char *allocation ;

    allocation = malloc(sizeof(char) * );
    index = 0;
    while (string[index] && index <= position)
    {

    }
}
char **stringputinstring(char *string)
{
    char **allocation ;
    int index ;
    int flag ;
    int totatallines ;

    flag = 0;
    index = 0;
    totatallines = checkhowmany(string) + 1;
    allocation = malloc(sizeof(char **) * totatallines + 1);
    if (!allocation)
    {
        free(allocation);
        return 0;
    }
    while (string[index] && string[index] != '\n')
        index++ ;
    if (string[index] == '\n')
    {

    }
    
}   
