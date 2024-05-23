//./file_rle -c input.txt output.rl1 R
//./file_rle -d output.rl1 decompressed.txt R


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rle_compress(FILE *input, FILE *output, char rle_char) {
    int current, count;
    int prev = EOF;

    while ((current = fgetc(input)) != EOF) {
        count = 1;
        while ((current == prev) && (count < 9)) {
            count++;
            current = fgetc(input);
        }

        if (prev != EOF) {
            if (count > 1 || prev == rle_char) {
                fprintf(output, "%c%c%d", rle_char, prev, count);
            } else {
                fputc(prev, output);
            }
        }
        prev = current;
    }

    if (prev != EOF) {
        if (count > 1 || prev == rle_char) {
            fprintf(output, "%c%c%d", rle_char, prev, count);
        } else {
            fputc(prev, output);
        }
    }
}

void rle_decompress(FILE *input, FILE *output, char rle_char) {
    int current, count;
    char next_char;

    while ((current = fgetc(input)) != EOF) {
        if (current == rle_char) {
            next_char = fgetc(input);
            count = fgetc(input) - '0';
            for (int i = 0; i < count; i++) {
                fputc(next_char, output);
            }
        } else {
            fputc(current, output);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <mode> <input_file> <output_file> <rle_char>\n", argv[0]);
        fprintf(stderr, "mode: -c to compress, -d to decompress\n");
        return 1;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char rle_char = argv[4][0];

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Failed to open input file");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        return 1;
    }

    if (strcmp(mode, "-c") == 0) {
        rle_compress(input, output, rle_char);
    } else if (strcmp(mode, "-d") == 0) {
        rle_decompress(input, output, rle_char);
    } else {
        fprintf(stderr, "Invalid mode. Use -c to compress and -d to decompress.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}
