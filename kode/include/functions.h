#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define MAX_PASSWORD_LENGTH 1000

FILE *openfile(char* filename, char *mode);
int compare(char *password, char *salt, char *input_hash);
void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash);
char* brute_force_attack(char* encrypted_password, char* salt);
char* generate_words(char *str, int index, int length, char *input_hash, char *salt);

#endif 