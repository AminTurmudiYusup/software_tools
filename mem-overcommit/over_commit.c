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

    size_t total_size = num_pages * PAGE_SIZE;
    char *memory = malloc(total_size);

    if (memory == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

 printf("Allocated %zu bytes of memory.\n", total_size);

 for (size_t i = 0; i < num_pages; i++) {
        char *page = memory + (i * PAGE_SIZE); // Calculate the address of the current page

        if (strcmp(operation, "write") == 0) {
            // Write operation: Fill each byte of the page with a pattern
            for (size_t j = 0; j < PAGE_SIZE; j++) {
                page[j] = (char)(i % 256); // Assign a repeating pattern
            }
            printf("Wrote to page %zu at address %p.\n", i, (void *)page);

        } else if (strcmp(operation, "read") == 0) {
            // Read operation: Sum all values in the page
            unsigned long long sum = 0;
            for (size_t j = 0; j < PAGE_SIZE; j++) {
                sum += page[j];
            }
            printf("Read from page %zu at address %p, checksum: %llu.\n", i, (void *)page, sum);
        }

        // Pause after every PAUSE_FREQUENCY pages
        if (i % PAUSE_FREQUENCY == 0 && i != 0) {
            printf("Pausing for %d microseconds...\n", PAUSE_DURATION);
            usleep(PAUSE_DURATION); // Pause for PAUSE_DURATION microseconds
        }
    }


 free(memory); // Free the allocated memory
 printf("Memory freed.\n");

    return 0;
}