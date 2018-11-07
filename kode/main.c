#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

//Eventuelt sette inn valid_chars i en .h fil - DONE
//static const char valid_chars[] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";
//static const int valid_char_length = sizeof(valid_chars - 1);


/*

Sette opp struct og bruke eks data.input_hash = argv[1]

HUSK PÅ Å FREE VED SLUTT

typedef struct {
    
    char salt[16];
    char password[1000];
    char input_hash;

};
*/

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

    dictionary_attack(password, dictionary, salt, input_hash);

    fclose(dictionary);

    // Om passordet ikke finnes i .txt så vil brute force starte opp
    printf("Password was not found in dictionary.\n");
    printf("\n");
  
    return 0;
}

