#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

int main(int argc, char* argv[])
{
    
    if(argc != 2)
    {
        printf("Argumentet needed");
        exit(1);
    }

    char str[1000];
    char *input_hash = argv[1];
    char salt[16];
 
    memcpy(salt, input_hash, 12);
    printf("%s\n", salt);

    FILE *ftpr = fopen("dictionary.txt", "r");
    if(!ftpr)
    {
        printf("Error, cannot open file..\n");
        return -1;
    }

    printf("searching for hash: %s\n", input_hash);
    while(fgets(str, 1000, ftpr) != NULL) 
    {
        char* encrypted=crypt(str,salt);
       // printf("%s\n", encrypted);
        if(strcmp(encrypted, input_hash) == 0)
        {
            printf("Found password: %s", encrypted);
        }
        
    }

    fclose(ftpr);
    return 0;
}
