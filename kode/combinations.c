#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>


void combo(char *str, int index, int len)
{
    char c;
    char saltchars[]="abcdefghikjlmnopqrstuvWxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";

    if(index < (len -1))
    {
        for(c = 'a'; c <= 'c'; c++) 
        {
            str[index] = c;
            combo(str, index + 1, len);
        }

    }
    else
    {   
        for(c = 'a'; c <= 'c'; c++) 
        {
            str[index] = c;
            printf("%s\n", str);
        }

    }
}

#define LENGTH 3

int main(int argc, char **argv)
{
    char str[LENGTH+ 1];

    memset(str, 0, LENGTH +1);
    combo(str, 0, LENGTH);
    return 0;
}

 
