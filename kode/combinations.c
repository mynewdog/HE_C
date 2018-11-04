#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>


void combo(char *str, int index, int len)
{
    char c;

    if(index < (len -1))
    {
        for(c = 'a'; c <= 'z'; c++) 
        {
            str[index] = c;
            combo(str, index + 1, len);
        }

    }
    else
    {   
        for(c = 'a'; c <= 'z'; c++) 
        {
            str[index] = c;
            printf("%s\n", str);
        }

    }
}

#define LENGTH 10

int main(int argc, char **argv)
{
    char str[LENGTH+ 1];
    //char saltchars[]="abcdefghikjlmnopqrstuvWxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";

    char saltchars[]="abcdefg";



    memset(saltchars, 0, LENGTH +1);
    combo(saltchars, 0, LENGTH);
    return 0;
}

 
