/*
input:
  target str to modify, a substr to replace, and a substr to replace with
output:
  both the original and modified str
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 200
#define CHAR_SIZE sizeof(char)

// helper func to dynamically allocate space when assigning buffers
char* assign_buffer(char *b) {    
    // used calloc instead of malloc to protect from seg fault, or even worse...
    char *new = calloc(strlen(b)+1, CHAR_SIZE);
    strcpy(new, b);
    free(b);
    return new;
}

// wrapper for scanf(), similar to python's input()
char* input(const char *prmpt, const char *fmt) {
    char *b = calloc(BUFFER_SIZE, CHAR_SIZE);
    
    printf("%s\n", prmpt); scanf(fmt, b); 

    return assign_buffer(b);
}

int main() {
    char *str, *oldsub, *newsub;
    
    str = input("Enter a string: ", " %[^\n]");
    oldsub = input("Enter the substring to replace: ", "%s");
    newsub = input("Enter the string to replace with: ", "%s");
    
    printf("-----------------------\n");
     
    /*
    the max possible length of the modified str can be defined as:
      len(original_str) + max possible new chars to add
    
    the max possible new chars to add can be defined as:
      if len(old_substr) > len(new_substr):
        zero
      otherwise:
        max possible occurences of old_substr in original_str
                        *
        len(new_substr) - len(old_substr)  
    */ 

    char *out, *cur, *nxt;

    size_t max_out = strlen(str) + (
        strlen(newsub) > strlen(oldsub) 
        ? (strlen(str)/strlen(oldsub)) * (strlen(newsub)-strlen(oldsub))
        : 0);
    out = calloc(max_out+1, CHAR_SIZE);
    
    cur = str;
    nxt = strstr(cur, oldsub);

    while (nxt) {
        strncat(out, cur, nxt-cur);
        strcat(out, newsub);
        cur = nxt + strlen(oldsub);
        nxt = strstr(cur, oldsub);
    }
    strcat(out, cur); // append any remaining chars from original str
    
    printf("%s\n", str);
    printf("%s\n", out);

    free(str); free(oldsub); free(newsub); free(out);
    
    return 0;
}
