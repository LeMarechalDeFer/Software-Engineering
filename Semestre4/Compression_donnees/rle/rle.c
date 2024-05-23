

// Quand Utiliser un Séparateur
// Pas nécessaire pour de petites répétitions : Lorsque le nombre de répétitions est toujours inférieur à 10, 
// on peut se permettre de ne pas utiliser de séparateur, car un chiffre suffira pour représenter la répétition.

// Obligatoire pour des répétitions plus grandes : Si les séquences de répétitions peuvent dépasser 9, 
// l'absence de séparateur peut rendre la décompression ambiguë.

#include <stdio.h>
#include <string.h>

void rle_compress(const char* input, char* output) {
    int len = strlen(input);
    int count;
    char current;

    int out_index = 0;

    for (int i = 0; i < len; i++) {
        current = input[i];
        count = 1;

        while (i + 1 < len && input[i + 1] == current) {
            count++;
            i++;
        }

        output[out_index++] = current;
        output[out_index++] = '0' + count; // Convert count to char
    }

    output[out_index] = '\0'; // Null-terminate the output string
}

int main() {
    char input[] = "aaabbccccdee";
    char output[100];

    rle_compress(input, output);

    printf("Input: %s\n", input);
    printf("Compressed: %s\n", output);

    return 0;
}
