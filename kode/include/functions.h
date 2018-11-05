#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

FILE *openfile(char* filename, char *mode);
int compare(char *password, char *salt, char *input_hash);
void dictionary_attack(char *password, FILE *dictionary, char *salt, char *input_hash);

#endif 