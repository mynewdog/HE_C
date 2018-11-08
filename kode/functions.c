#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "include/functions.h"

static const char passchars[] =
    "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY"
    "Z1234567890+\"#&/()=?!@$|[]|{}";

static const int passchars_length = sizeof(passchars) - 1;

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
   og kjører compare funksjonen mot hvert passord som blir hentet inn */

void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash)
{

    while (fgets(password, MAX_PASSWORD_LENGTH, dictionary) != NULL)
    {
        int length = strlen(password);

        /* Omgjør alle \n til null terminatorer for å unngå bugs
           ettersom hver linje kun skal være ett passord */

        if (password[length - 1] == '\n')
        {
            password[length - 1] = '\0';
        }

        compare(password, salt, input_hash);
    }
}

/* Funksjon til å generer ord rekursivt.
   Begynner med én char, sammenligner og deretter går over til to chars osv
*/

char *generate_words(char *word, int index, int length, char *input_hash, char *salt)
{
    for (int i = 0; i < passchars_length; i++)
    {
        word[index] = passchars[i];

        if (index == length - 1)
        {
            compare(word, salt, input_hash);
        }
        else
        {
            char *password_found = generate_words(word, index + 1, length, input_hash, salt);
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
    char *word = calloc(1, max_length + 1);

    for (int length = 1; length <= max_length; length++)
    {
        memset(word, 0, max_length + 1); // Fyller opp word med 0

        char *password_found = generate_words(word, 0, length, input_hash, salt);
        if (password_found != NULL)
        {
            return password_found;
        }
    }

    return NULL;
}