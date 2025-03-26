#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("creating ptr\n");
    int *ptr = (int *)calloc(5, sizeof(int));

    printf("gonna free its mem now lol...\n");
    free(ptr);

    printf("hey guess what\n");
    scanf("%d", ptr);
    
    int* chkbt = ptr;
    printf("%d", *chkbt);

}