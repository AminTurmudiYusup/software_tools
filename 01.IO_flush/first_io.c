#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    
    puts("STDOUT\n");             
    fprintf(file, "STDOUT\n");    

  
    fputs("STDER\n", stderr);    
    fprintf(file, "STDER\n");

    fclose(file);
    return 0;
}
