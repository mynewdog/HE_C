#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("To use this program you need to input a hash value as second parameter\n");
        exit(1);
    }

    char password[MAX_PASSWORD_LENGTH];
    char *input_hash = argv[1];
    char salt[16];
    int brute_length;
    
    // Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);
  
    FILE* dictionary = fopen("crypto/dictionary.txt", "r");

    if(!dictionary)
    {
        printf("Error, cannot open file..\n");
        exit(1);
    }


    // Starter dictionary attack som tar i bruk compare funksjonen
    printf("Searching for password in dictionary file..\n");

    //Dictionary attack funker.
    dictionary_attack(password, dictionary, salt, input_hash);

    fclose(dictionary);

    // Om passordet ikke finnes i .txt så vil brute force starte opp
    printf("Password was not found in dictionary.\n");
    printf("Enter a password length to start brute force attack \n");

    scanf("%i\n", &brute_length);
    
  
    return 0;
}

