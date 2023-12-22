
#include "mapchek.h"

typedef struct mapvlidity
{
    int player ;
    int collectiles ;
    int  runout ;

} t_map ;

int checkvalidity(int player, int collec,int out)
{
    if (player != 1)
    {
        printf("Player's must only be one");
        return 1 ;
    }
    if (collec < 2 )
    {
        printf("Collectibles are less then one");
        return 1 ;
    }
    if (out != 1)
    {
        printf("It must be one Exit !");
        return 1 ;
    }
    return 0 ;
}
int checkmapvaliditiy(char *string)
{
    t_map mymap;
    int index ;
    int check ;

    check = 0 ;
    index = 0 ;
    mymap.player = 0 ;
    mymap.collectiles = 0;
    mymap.runout = 0; 

    while (string[index])
    {
        if (string[index] == 'P')
            mymap.player+= 1;
        if (string[index] == 'C')
            mymap.collectiles+= 1;
        if (string[index] == 'E')
            mymap.runout+= 1 ;
        index++ ;
    }
    printf(" {%d} {%d} {%d}",mymap.player , mymap.collectiles ,mymap.runout);
    check = checkvalidity(mymap.player , mymap.collectiles ,mymap.runout);
    return check ;
}
int maplenghtcheck(char **string)
{
    int index = 0 ;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
int main()
{
    int fd = 0 ;
    fd = open("txt.txt" , O_RDONLY);
    char *string = functionfilereader(fd);
    char **res = stringreturn(string);
    printf("%s" , res[0]);
}