#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int compare_brute(char *str, char *salt, char *input_hash)
{
     char* encrypted_password = crypt(str,salt);
     char* compareEncrypted = encrypted_password;

        if(strcmp(compareEncrypted, input_hash) == 0)
        {
            printf("Found hash: %s\n", encrypted_password);
            printf("The password is: %s\n", str);
            exit(1);
        }
    return 0;
}

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
/* Function to print permutations of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void permute(char *str, char *salt, char *input_hash, int index, int length) 
{ 
   int i; 
   if (index == length) 
   {
     /*printer alle kombinasjoner  
     printf("%s\n", str); 
     */
     compare_brute(str, salt, input_hash); 
   }
   else
   { 
       for (i = index; i <= length; i++) 
       { 
          swap((str+index), (str+i)); 
          permute(str, salt, input_hash, index+1, length); 
          swap((str+index), (str+i)); //backtrack 
       } 
   } 
} 
  

// hash for abc $1$abcdefgh$Kn5qrjcQzV7oAHBJ23Cu3/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("To use this program you need to input a hash value as second parameter\n");
        exit(1);
    }

    char *input_hash = argv[1];
    char salt[16];
    memcpy(salt, input_hash, 12);


    char str[] = "a?Z@"; 
    int n = strlen(str); 
    permute(str, salt, input_hash, 0, n-1); 
    return 0; 
        

}
