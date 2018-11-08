#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define MAX_PASSWORD_LENGTH 1000
#define SALT_LENGTH 12

FILE *openfile(char *filename, char *mode);
int compare(const char *password, const char *salt, const char *input_hash, char *encrypted_password);
int dictionary_attack(char *password, FILE *dictionary, char *salt, const char *input_hash, char *encrypted_password);
char *brute_force_attack(const char *input_hash, char *salt, char *encrypted_password);
char *generate_words(char *str, int index, int length, const char *input_hash, char *salt, char *encrypted_password);

#endif