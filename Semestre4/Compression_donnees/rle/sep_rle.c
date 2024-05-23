#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encodeRLE(char* input, char sep) {
    int len = strlen(input);
    // Allocating space for the output. In the worst case scenario, the output length could be 2 * len (if no repetitions).
    char* output = (char*)malloc(2 * len + 1);
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int out_index = 0;
    int count;

    for (int i = 0; i < len; i++) {
        char current = input[i];
        count = 1;

        // Count the number of repetitions of the current character
        while (i + 1 < len && input[i + 1] == current) {
            count++;
            i++;
        }

        // If the count is greater than 1, we encode it with the separator and count
        if (count > 1 || current == sep) {
            out_index += sprintf(&output[out_index], "%c%c%d", sep, current, count);
        } else {
            // Otherwise, we just copy the character
            output[out_index++] = current;
        }
    }

    output[out_index] = '\0'; // Null-terminate the output string

    return output;
}

int main() {
    char* input = "aaaaaaaaaaaaaaaabcdegaaaaaapooorrttamsxccccc";
    char sep = '\\';
    char* encoded = encodeRLE(input, sep);
    printf("%s\n", encoded);
    free(encoded); // Free the allocated memory for the output string
    return 0;
}
