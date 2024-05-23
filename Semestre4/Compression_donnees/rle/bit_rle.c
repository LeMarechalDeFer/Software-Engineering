//./rle -c input_file output_file.rl2
//./rle -d input_file.rl2 output_file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour lire un fichier et le convertir en une chaîne binaire
char *read_binary_file(const char *filename, long *file_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(size);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, size, file);
    fclose(file);

    *file_size = size;
    return buffer;
}

// Fonction pour convertir un octet en chaîne binaire
void byte_to_binary(unsigned char byte, char *bin_str) {
    for (int i = 7; i >= 0; --i) {
        bin_str[i] = (byte & 1) ? '1' : '0';
        byte >>= 1;
    }
}

// Fonction pour compresser une chaîne binaire en utilisant l'algorithme RLE
void rle_compress_bits(const char *input, FILE *output) {
    int len = strlen(input);
    int zero_count = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] == '0') {
            zero_count++;
        } else { // input[i] == '1'
            if (zero_count > 0) {
                fprintf(output, "%d", zero_count);
                zero_count = 0;
            }
            fputc('1', output);
        }
    }
    if (zero_count > 0) {
        fprintf(output, "%d", zero_count);
    }
}

// Fonction pour lire une chaîne binaire et la décoder en utilisant l'algorithme RLE
void rle_decompress_bits(const char *input, FILE *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '1') {
            fputc('1', output);
        } else {
            int zero_count = 0;
            while (i < len && input[i] >= '0' && input[i] <= '9') {
                zero_count = zero_count * 10 + (input[i] - '0');
                i++;
            }
            i--; // Ajustement car la boucle for l'incrémentera encore
            for (int j = 0; j < zero_count; j++) {
                fputc('0', output);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <mode> <input_file> <output_file>\n", argv[0]);
        fprintf(stderr, "mode: -c to compress, -d to decompress\n");
        return 1;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    long file_size;
    char *buffer = read_binary_file(input_file, &file_size);
    if (!buffer) {
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Failed to open output file");
        free(buffer);
        return 1;
    }

    if (strcmp(mode, "-c") == 0) {
        // Convertir chaque octet en une chaîne binaire
        char *binary_str = (char *)malloc(file_size * 8 + 1);
        if (!binary_str) {
            perror("Failed to allocate memory for binary string");
            fclose(output);
            free(buffer);
            return 1;
        }
        binary_str[0] = '\0';

        char bin[9];
        bin[8] = '\0';
        for (long i = 0; i < file_size; i++) {
            byte_to_binary((unsigned char)buffer[i], bin);
            strcat(binary_str, bin);
        }

        // Compresser la chaîne binaire
        rle_compress_bits(binary_str, output);
        free(binary_str);
    } else if (strcmp(mode, "-d") == 0) {
        // Lire le fichier compressé en tant que chaîne de caractères
        buffer[file_size] = '\0'; // Assurer que le buffer est une chaîne de caractères
        // Décompresser la chaîne binaire
        rle_decompress_bits(buffer, output);
    } else {
        fprintf(stderr, "Invalid mode. Use -c to compress and -d to decompress.\n");
        fclose(output);
        free(buffer);
        return 1;
    }

    fclose(output);
    free(buffer);

    return 0;
}
