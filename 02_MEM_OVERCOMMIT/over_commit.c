#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define PAGE_SIZE 4096       // 4 KiB
#define PAUSE_FREQUENCY 1000 // Pause after 1000 pages
#define PAUSE_DURATION 50000 // Pause for 50 milliseconds (50,000 microseconds)

int main(int argc, char *argv[]) {
 if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_pages> <operation: read|write>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    size_t num_pages = atoi(argv[1]); // Number of pages to allocate
    char *operation = argv[2];       // Operation: "read" or "write"

    if (num_pages == 0 || (strcmp(operation, "read") != 0 && strcmp(operation, "write") != 0)) {
        fprintf(stderr, "Invalid arguments. Use a positive number of pages and operation 'read' or 'write'.\n");
        return 1;
    }

return 0;
}