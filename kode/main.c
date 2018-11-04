#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

char saltchars[]="abcdefghikjlmnopqrstuvWxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";

FILE *openfile(char* filename, char* mode);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("To use this program you need to input a hash value as second parameter");
        exit(1);
    }

    char password[1000];
    char *input_hash = argv[1];
    char salt[16];
    
    //Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);
  
    FILE* dictionary = openfile("crypto/dictionary.txt", "r");

    //Starten av dictionary attack

    printf("Searching for password in dictionary\n");
    while(fgets(password, 1000, dictionary) != NULL) 
    {
        int length = strlen(password);
        if(password[length-1] == '\n')
        {
            password[length-1] = '\0';
        }
        
        char* encrypted_password = crypt(password,salt);
        char* compareEncrypted = encrypted_password;

        if(strcmp(compareEncrypted, input_hash) == 0)
        {
            printf("Found hash: %s\n", encrypted_password);
            printf("The password is: %s\n", password);
            exit(1);
        }
        
    }
    fclose(dictionary);

    printf("Password was not found in dictionary.\n");
    printf("Want to decide password length?");

    return 0;
}

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

