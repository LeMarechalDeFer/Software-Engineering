#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeRLE(char* inputFile, char* outputFile) {
	FILE* input = fopen(inputFile, "r");
	FILE* output = fopen(outputFile, "w");

	if (input == NULL || output == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

	char sep;
	printf("Entrez le séparateur : ");
	scanf("%c", &sep);

	int count = 1;
	char current = fgetc(input);

	while (current != EOF) {
		char tmp = fgetc(input);
		if (current == tmp) {
			count++;
		}
		else {
			if (count > 1)
				fprintf(output, "%c%d%c", sep, count, current);
			else
				fprintf(output, "%c", current);

			count = 1;
			current = tmp;
		}
	}

	fclose(input);
	fclose(output);
}

void decodeRLE(char* inputFile, char* outputFile) {
	FILE* input = fopen(inputFile, "r");
	FILE* output = fopen(outputFile, "w");

	if (input == NULL || output == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

	int count = 1;
	char character;
	char sep;
	printf("Entrez le séparateur : ");
	scanf("%c", &sep);

	while (fscanf(input, "%c", &character) != EOF) {
		char tmp;
		if (character == sep)
			fscanf(input, "%d%c", &count, &tmp);
		else
			tmp = character;

		for (int i = 0; i < count; i++) {
			fprintf(output, "%c", tmp);
		}
		count = 1;
	}

	fclose(input);
	fclose(output);
}


void encodeBits(char* inputFile, char* outputFile) {
	FILE* input = fopen(inputFile, "rb");
	FILE* output = fopen(outputFile, "wb");
	FILE* output2 = fopen("./resources/databitsSimu.txt", "wb");

	if (input == NULL || output == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

	int count = 0;
	char current;

	unsigned char buffer;

	int prev = 0;
	while (fread(&buffer, sizeof(unsigned char), 1, input) == 1) {
		for (int i = 0; i < 8; i++) {
			if ((buffer >> 7 - i) & 1)
				fwrite("1", sizeof(unsigned char), 1, output2);
			else
				fwrite("0", sizeof(unsigned char), 1, output2);
			if ((buffer >> 7 - i) & 1) {
				if (count > 0) {
					char buf[8];
					_itoa(count, &buf, 10);

					fwrite(&buf, sizeof(char), 1, output);
					count = 0;
				}
				else if (prev == 1) {
					fwrite("0", sizeof(char), 1, output);
				}
			}
			else {
				count++;
			}
			prev = (buffer >> 7 - i) & 1;
		}
	}

	fclose(input);
	fclose(output);
}

void decodeBits(char* inputFile, char* outputFile) {
	FILE* input = fopen(inputFile, "r");
	FILE* output = fopen(outputFile, "w");

	if (input == NULL || output == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

	int count;
	char character;

	while (fscanf(input, "%c", &character) != EOF) {
		count = atoi(&character);
		for (int i = 0; i < count; i++) {
			fprintf(output, "0");
		}

		fprintf(output, "1");

	}

	fclose(input);
	fclose(output);
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("Utilisation : %s <encode|decode|encodeBits|decodebits> <inputFile> <outputFile>\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (strcmp(argv[1], "encode") == 0) {
		encodeRLE(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "decode") == 0) {
		decodeRLE(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "encodeBits") == 0) {
		encodeBits(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "decodebits") == 0) {
		decodeBits(argv[2], argv[3]);
	}
	else {
		printf("Option invalide : %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
