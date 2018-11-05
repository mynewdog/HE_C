#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

static const char valid_chars[] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";
static const int valid_char_length = sizeof(valid_chars - 1);

FILE *openfile(char* filename, char* mode);
int compare(char *password, char *salt, char *input_hash);
void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("To use this program you need to input a hash value as second parameter\n");
        exit(1);
    }

    char password[1000];
    char *input_hash = argv[1];
    char salt[16];
    
    //Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);
  
    FILE* dictionary = openfile("crypto/dictionary.txt", "r");

    //Starter dictionary attack som tar i bruk compare funksjonen
    dictionary_attack(password, dictionary, salt, input_hash);
    fclose(dictionary);

    printf("Password was not found in dictionary.\n");
    printf("Want to decide password length?\n");

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
    printf("Searching for password in dictionary\n");
    while(fgets(password, 1000, dictionary) != NULL) 
    {
        int length = strlen(password);

        if(password[length-1] == '\n')
        {
            password[length-1] = '\0';
        }

        compare(password, salt, input_hash);
    }
}