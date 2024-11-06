#include <stdio.h>

void printFflush(){

    puts("STDOUT With fflush");  
    fflush(stdout);

    fputs("STDER With fflush", stderr); 
    fflush(stderr);
}


void printN(){

    puts("STDOUT With N \n");  

    fputs("STDER With N \n", stderr); 
}

int printNAndWriteFile(){

   FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    
    puts("STDOUT With N \n");             
    fprintf(file, "STDOUT With N \n");    

  
    fputs("STDER With N \n", stderr);    
    fprintf(file, "STDER With N \n");

    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <option>\nOptions:\n a - printFflush\n b - printN\n c - printNAndWriteFile\n", argv[0]);
        return 1;
    }

    char option = argv[1][0];  // Get the first character of the argument

    switch (option) {
        case 'a':
            printFflush();
            break;
        case 'b':
            printN();
            break;
        case 'c':
            printNAndWriteFile();
            break;
        default:
            fprintf(stderr, "Unknown option: %c\n", option);
            return 1;
    }

    return 0;
}
