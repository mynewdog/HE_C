#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

static const char alphabet[] =
    "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY"
    "Z1234567890+\"#&/()=?!@$|[]|{}";

static const int alphabet_size = sizeof(alphabet) - 1;

/* Åpner filen og sørger for at det faktisk finnes en fil */

FILE *openfile(char *filename, char *mode)
{
    FILE *file;

    file = fopen(filename, mode);
    if (!file)
    {
        printf("Error, cannot open file..\n");
        exit(1);
    }

    return file;
}

/* Compare sammenligner et passord fra dictionary som blir 
   kryptert og deretter sammenligner med hash value */

int compare(char *password, char *salt, char *input_hash)
{
    char *encrypted_password = crypt(password, salt);
    char *compareEncrypted = encrypted_password;

    if (strcmp(compareEncrypted, input_hash) == 0)
    {
        printf("Found hash: %s\n", encrypted_password);
        printf("Which matches the password: %s\n", password);
        exit(1);
    }
    return 0;
}

/* Dictionary_attack som går igjennom hvert passord i filen
   og sammenligner passordet når det blir omgjort til en hash-verdi mot input_hash */

void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash)
{

    while (fgets(password, MAX_PASSWORD_LENGTH, dictionary) != NULL)
    {
        int length = strlen(password);

        /* Omgjør alle \n til null terminatorer 
           ettersom hver linje kun skal være ett passord */

        if (password[length - 1] == '\n')
        {
            password[length - 1] = '\0';
        }

        compare(password, salt, input_hash);
    }
}

// Recursive character permutation

char *permutations(char *str, int index, int length, char *input_hash, char *salt)
{
    for (int i = 0; i < alphabet_size; i++)
    {
        str[index] = alphabet[i];

        if (index == length - 1)
        {
            compare(str, salt, input_hash);
        }
        else
        {
            char *password_found = permutations(str, index + 1, length, input_hash, salt);
            if (password_found != NULL)
            {
                return password_found;
            }
        }
    }
    return NULL;
}

char *brute_force_attack(char *input_hash, char *salt)
{
    int max_length = 32;
    char *str = calloc(1, max_length + 1);

    for (int length = 1; length <= max_length; length++)
    {
        memset(str, 0, max_length + 1); // fill word with NULL bytes

        char *password_found = permutations(str, 0, length, input_hash, salt);
        if (password_found != NULL)
        {
            return password_found;
        }
    }

    return NULL;
}
