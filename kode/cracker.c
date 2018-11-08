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
    const char *input_hash = argv[1];
    char *salt = malloc(sizeof(char) * SALT_LENGTH + 1);
    salt[SALT_LENGTH] = '\0';
    char *encrypted_password = malloc(sizeof(char));

    // Kopierer over salt fra input_hash
    memcpy(salt, input_hash, SALT_LENGTH);

    FILE *dictionary = openfile("crypto/smalldict.txt", "r");

    /* Starter dictionary attack og hvis 
       ikke passord finnes så kjøres brute_force */

    printf("\n");
    printf("Cracker is now running\n");

    printf("--------------------------\n");
    printf("Starting dictionary attack\n");
    printf("--------------------------\n");

    if (dictionary_attack(password, dictionary, salt, input_hash, encrypted_password) != 1)
    {

        printf("Password was not found in the dictionary.\n\n");
        printf("---------------------------\n");
        printf("Starting brute force attack\n");
        printf("---------------------------\n");

        brute_force_attack(input_hash, salt, encrypted_password);
    }

    fclose(dictionary);
    free(salt);
    free(encrypted_password);

    return 0;
}
