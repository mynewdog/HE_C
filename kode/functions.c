#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

/* Åpner filen og sørger for at det faktisk finnes en fil */

FILE *openfile(char* filename, char* mode)
{
    FILE *file;

    file = fopen(filename, mode);
    if(!file)
    {
        printf("Error, cannot open file..\n");
        exit(1);
    }
    
    return file;
}

/* Compare sammenligner et passord fra dictionary som blir 
   kryptert og deretter sammenligner med hash value */ 

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

    while(fgets(password, MAX_PASSWORD_LENGTH, dictionary) != NULL) 
    {
        int length = strlen(password);

        /* Omgjør alle \n til null terminatorer 
           ettersom hver linje kun skal være ett passord */

        if(password[length-1] == '\n')
        {
            password[length-1] = '\0';
        }

        compare(password, salt, input_hash);
    }
    
}

/*

trenger crack(hash, salt);

void brute_force(int index, int length, char *salt, char *input_hash, char *password)
{
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++)
    {
        if (index < length)
        {
            brute_force(index + 1, length, salt, input_hash, password);
        }
        else
        {
            compare(password, salt, input_hash);
        }
    }
}

*/

