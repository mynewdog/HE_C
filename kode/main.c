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
        printf("To use this program you need to input a hash value as second parameter");
        exit(1);
    }

    char password[1000];

    //input_hash er hash verdien som blir gitt ved input
    char *input_hash = argv[1];
    //Så mye som skal lagres i salt
    char salt[16];
    
    //Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);
  
    FILE *ftpr = fopen("dictionary.txt", "r");
    if(!ftpr)
    {
        printf("Error, cannot open file..\n");
        return -1;
    }

    //Starten av dictionary attack
    printf("Searching for password in dictionary\n");
    while(fgets(password, 1000, ftpr) != NULL) 
    {
        int length = strlen(password);
        //Gjør om alle \n verdier til en null terminator
        if(password[length-1] == '\n')
        {
            password[length-1] = '\0';
        }
        
        char* encrypted=crypt(password,salt);
        char* compareEncrypted = encrypted;

        if(strcmp(compareEncrypted, input_hash) == 0)
        {
            printf("Found hash: %s\n", encrypted);
            printf("The password is: %s\n", password);
            exit(1);
        }
        
    }

    fclose(ftpr);

    printf("Password was not found in dictionary.\n");
    printf("Want to decide password length?");


    

    return 0;
}
