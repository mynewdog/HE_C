#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"
#define MAX_PASSWORD_LENGTH 1000

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

//Compare sammenligner et passord fra dictionary som blir kryptert og deretter sammenlignet med hash value

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
    /*gjøre om til en for loop for å kunne bruke openMP (?)
        pseudo 
        
        printf("dict attack");
        fseek(dictionary, 0, SEEK_END);
        int bufsize = ftell(dictionary);
        printf("%i", bufsize);

     
            for(int i = 0; i < bufsize ; i++) 
            {
                int length = strlen(password);
                if(password[length-1] == '\n') { password[length-1] = '\0';}
                compare(password, salt, input_hash);
            }
        
        */
        
    while(fgets(password, MAX_PASSWORD_LENGTH, dictionary) != NULL) 
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
