#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mapchek.h"

int linefounder(char *string)
{
    int index = 0 ;
    int flag = 0;
    while (string[index])
    {
        if (string[index] == '\n')
            flag++ ;
        index++ ;
    }
    return flag + 1;
}
int lencount(char *string)
{
    int index = 0 ;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
char *makeacopy(char *string)
{
    int index = 0;
    char *allocation ;
    allocation = malloc(sizeof(string) * lencount(string) + 1);
    if (!allocation)
        return (NULL);
    while(string[index])
    {
        allocation[index] = string[index] ;
        index++ ;
    }
    allocation[index] = '\0';
    return (allocation);

}   
char *stringmove(char *string , int index)
{
    int increment = 0 ;
    char *allocation ;
    allocation = malloc(sizeof(char) * index + 1);
    if (!allocation)
        return (NULL);
    while (string[increment] && increment <= index )
    {
        allocation[increment] = string[increment] ;
        increment++ ;
    }
    allocation[increment] = '\0';
    return (allocation) ;
} 
char **string(char *string)
{
    int index = 0 ;
    int i = 0;
    int checkpoint = 0 ;
    int res = linefounder(string);
    char **allocation ;

    allocation = malloc(sizeof(char **) * res + 1);
    if (!allocation)
        return (NULL);
    while (string[index])
    {
        if (string[index] == '\n')
        {
            checkpoint = index ;
            allocation[i] = stringmove(string, checkpoint);
            checkpoint++ ;
             string = makeacopy(&string[checkpoint]);
             i++ ;
        }
        index++ ;
    }
    allocation[i] = NULL;
    return allocation;
}
int main()
{
    int fd = 0 ;
    fd = open("txt.txt" , fd);
    char *res = functionfilereader(fd);
    char **rus = string(res);
    printf("%s)- \n" , res);
    printf("\n");
    int i = 0;
    while (i < 6)
    {
        printf("%s\n" ,rus[i] );
        i++ ;
    }
}
