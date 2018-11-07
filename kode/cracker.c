#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("To use this program you need to input a hash value as second parameter\n");
        exit(1);
    }

    char password[MAX_PASSWORD_LENGTH];
    char *input_hash = argv[1];
    char salt[16];

    // Kopierer over salt fra input_hash
    memcpy(salt, input_hash, 12);

    // ÅPNER FEIL DICTIONARY ATM la bruker skrive inn dictionary eg include/bigdict.txt
    FILE *dictionary = fopen("crypto/smalldict.txt", "r");

    if (!dictionary)
    {
        printf("Error, cannot open file..\n");
        exit(1);
    }

    // Starter dictionary attack
    printf("\n------------------------------\n");
    printf("Cracker 07/11/18 is now running\n");
    printf("-------------------------------\n");

    printf("**************************\n");
    printf("Starting dictionary attack\n");
    printf("**************************\n");
    printf("\n\nSearching for password in the dictionary\n");

    dictionary_attack(password, dictionary, salt, input_hash);
    fclose(dictionary);

    printf("Password was not found in the dictionary.\n\n");

    printf("***************************\n");
    printf("Starting brute force attack\n");
    printf("***************************\n");

    brute_force_attack(input_hash, salt);

    return 0;
}
