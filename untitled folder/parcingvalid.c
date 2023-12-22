#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mapchek.h"


char *thisfunctionreader(char *string , int fd , int size) 
{ 
    int readsize = 1;

    while (fd >= 0&& size > 0)
    {
        readsize = read(fd , string , size);
        if (readsize <= 0)
        {
            free(string);
            return (0);
        }
        string[readsize] = '\0';
    }
    if (string)
        if (string[0] == '\0')
        {
            free(string);
            return (0);
        }
    return (string);
}
char *functionfilereader(int fd)
{
    int size = 10000;
    static char *text ;
    char *thistext ;

    if (fd < 0 )
        return (0) ;
    thistext = malloc(sizeof(char) * size + 1);
    thisfunctionreader(thistext ,fd ,  size );
    return thistext ;
}
