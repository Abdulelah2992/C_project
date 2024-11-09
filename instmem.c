#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    size_t chunk_size = 16;  // Adjust chunk size as needed
    unsigned char buffer[chunk_size];

    // Read the file in chunks
    while (fread(buffer, 1, chunk_size, file) == chunk_size) {
        // Process the chunk (for example, print each byte in hexadecimal)
        for (size_t i = 0; i < chunk_size; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\n");  // New line after each chunk
    }

    // Close the file
    fclose(file);

    return 0;
}

