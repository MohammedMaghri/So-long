#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mapchek.h"

int newlinecha(char *string)
{
    int index ;

    index = 0;
    
    while (string[index])
    {
        index++ ;
    }
    return (index);
}
char *thisfunctionreader(char *text ,char *string , int fd , int size) 
{ 
    int readsize = 1;

    while (fd >= 0 && newlinecha(string) == 0 && size > 0)
    {
        readsize = read(fd , string , size);
        if (readsize <= 0)
        {
            free(string);
            free(text);
            return (0);
        }
        string[readsize] = '\0';
    }
    if (text)
    {
        if (text[0] == '\0')
        {
            free(text);
            return (0);
        }
    }
    return (text);
}
char *functionfilereader(int fd)
{
    int size = 100;
    static char *text ;
    char *thistext ;

    if (fd < 0 )
    {
        return (0) ;
    }
    thistext = malloc(sizeof(char) * size + 1);
    text = thisfunctionreader(text , thistext ,fd ,  size );
    return thistext ;
}
int main ()
{
    int fd = 0 ;
    fd = open( "txt.txt" , fd);
    char *string ;
    string = functionfilereader(fd);
    int res = checkvalidmap(string);
    int turn = checkwithealllines(string , res);
    printf( "%d %d", turn , res );
}