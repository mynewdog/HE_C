#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define MAX_PASSWORD_LENGTH 1000

FILE *openfile(char* filename, char *mode);
int compare(char *password, char *salt, char *input_hash);
void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash);

static const char valid_chars[] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";
static const int valid_char_length = sizeof(valid_chars - 1);

#endif 