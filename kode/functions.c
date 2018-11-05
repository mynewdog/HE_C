#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

//Finne ut en måte å bruke argv[3]

FILE *openfile(char* filename, char* mode)
{
    FILE *file;

    file = fopen(filename, mode);
    if(!file)
    {
        printf("Error, cannot open file..\n");
        exit(1);
    }
    //Finne måte å returnere størrelsen så jeg kan bruke denne i dictionary_attack

    return file;
}

//Compare sammenligner 

int compare(char *password, char *salt, char *input_hash)
{
     char* encrypted_password = crypt(password,salt);
     char* compareEncrypted = encrypted_password;

        if(strcmp(compareEncrypted, input_hash) == 0)
        {
            printf("Found hash: %s\n", encrypted_password);
            printf("The password is: %s\n", password);
            exit(1);
        }
    return 0;
}


void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash)
{
    //gjøre om til en for loop
    while(fgets(password, 1000, dictionary) != NULL) 
    {
        int length = strlen(password);
        //Omgjør alle \n til null terminatorer 
        if(password[length-1] == '\n')
        {
            password[length-1] = '\0';
        }

        compare(password, salt, input_hash);
    }
}
