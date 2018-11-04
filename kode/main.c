#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

char saltchars[]="abcdefghikjlmnopqrstuvWxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";

int main(int argc, char* argv[])
{
    //Sjekk om argumenter er korrekt
    if(argc != 2)
    {
        printf("Argumentet needed");
        exit(1);
    }

    char str[1000];

    //input_hash er hash verdien som blir gitt ved input
    char *input_hash = argv[1];
    //Så mye som skal lagres i salt
    char salt[16];
    
    //Trimmer input_hash til saltet og printer som sjekk
    memcpy(salt, input_hash, 12);
    //printf("Salt from hash = %s\n", salt);

    //printf("The salt is:%s\n", salt);
  
    //Åpner filen
    FILE *ftpr = fopen("dictionary.txt", "r");
    if(!ftpr)
    {
        printf("Error, cannot open file..\n");
        return -1;
    }

    //Starten av brute force med dictionary
    printf("Searching for password in dictionary\n");
    while(fgets(str, 1000, ftpr) != NULL) 
    {
        int length = strlen(str);
        if(str[length-1] == '\n')
        {
            str[length-1] = '\0';
        }
        
        char* encrypted=crypt(str,salt);
        //printf("%s\n", encrypted);

        char* compareEncrypted = encrypted;


        if(strcmp(compareEncrypted, input_hash) == 0)
        {
            printf("Found hash: %s\n", encrypted);
            printf("The password is: %s\n", str);
            break;
        }
        
    }

    fclose(ftpr);
    return 0;
}
