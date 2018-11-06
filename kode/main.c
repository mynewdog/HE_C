#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

//Eventuelt sette inn valid_chars i en .h fil
//static const char valid_chars[] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";
//static const int valid_char_length = sizeof(valid_chars - 1);


/*

Sette opp struct og bruke eks data.input_hash = argv[1]

HUSK PÅ Å FREE VED SLUTT

typedef struct data
{
    
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

    char password[1000];
    char *input_hash = argv[1];
    char salt[16];
    
    // Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);
  
    FILE* dictionary = openfile("crypto/dictionary.txt", "r");


    // Starter dictionary attack som tar i bruk compare funksjonen
    printf("Searching for password in dictionary file..\n");

    dictionary_attack(password, dictionary, salt, input_hash);

    fclose(dictionary);

    printf("Password was not found in dictionary.\n");
    printf("\n");
    
    return 0;
}

