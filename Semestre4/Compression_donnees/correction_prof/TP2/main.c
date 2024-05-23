#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//Create a struct that can be used as a new type
struct node {
	int frequency;
	unsigned char character;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

struct chainedNode {
	Node* aNode;
	struct chainedNode* next;
	struct chainedNode* prev;
};
typedef struct chainedNode	ChainedNode;
char* charCoding[256] = { 0 };
Node* huffmanNode = NULL;


//////////////////////////////////////////
// ENCODE HUFFMAN
//////////////////////////////////////////

//Save the huffman tree in the output file
void saveTree(Node* aNode, FILE* output)
{
	if (aNode->left == NULL && aNode->right == NULL)
	{
		fprintf(output, "0");
		fprintf(output, "%c", aNode->character);
	}
	else
	{
		fprintf(output, "1");
		saveTree(aNode->left, output);
		saveTree(aNode->right, output);
	}
}

//Parse the tree to get the huffman code for each character
void parseTree(Node* node, char* code, int depth) {
	if (node != NULL && node->left == NULL && node->right == NULL) {
		printf("%c : %s\n", node->character, code);
		charCoding[(int)node->character] = malloc(strlen(code) + 1);
		strcpy(charCoding[(int)node->character], code, strlen(code));
	}
	else if (node != NULL) {
		code[depth] = '0';
		parseTree(node->left, code, depth + 1);
		code[depth + 1] = '\0'; //reset the code to the previous state'
		code[depth] = '1';
		parseTree(node->right, code, depth + 1);
		code[depth + 1] = '\0'; //reset the code to the previous state'
	}
}

//Encode the file using huffman algorithm
void encodeHuffman(char* inputFile, char* outputFile) {
	FILE* input = fopen(inputFile, "r");
	FILE* output = fopen(outputFile, "w");

	if (input == NULL || output == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}

	//parse the whole file to count how many times each character appears
	Node* chars[256] = { NULL };
	char current;
	while ((current = fgetc(input)) != EOF) {
		if (chars[current] == NULL) {
			chars[current] = (Node*)malloc(sizeof(Node));
			chars[current]->frequency = 1;
			chars[current]->character = current;
			chars[current]->left = NULL;
			chars[current]->right = NULL;
		}
		else
		{
			//increment the frequency of the character
			chars[current]->frequency++;
		}
	}
	//shift at the start of the array all the non null values
	int j = 0;
	for (int i = 0; i < 256; i++) {
		if (chars[i] != NULL) {
			chars[j] = chars[i];
			j++;
		}
	}

	//sort the count array by their frequency
	for (int i = 0; i < j; i++) {
		for (int k = i + 1; k < j; k++) {
			if (chars[k] != NULL && (chars[i]->frequency > chars[k]->frequency)) {
				Node* tmp = chars[i];
				chars[i] = chars[k];
				chars[k] = tmp;
			}
		}
	}

	//Create a data structure that will contain the huffman tree
	//Create a node for each character
	ChainedNode* firstNode = malloc(sizeof(ChainedNode));
	firstNode->aNode = chars[0];
	firstNode->next = NULL;
	firstNode->prev = NULL;
	ChainedNode* previousNode = firstNode;
	int i = 1;
	printf("%c : %d\n", firstNode->aNode->character, firstNode->aNode->frequency);

	while (chars[i] != NULL) {
		ChainedNode* newNode = malloc(sizeof(ChainedNode));
		newNode->aNode = chars[i];
		newNode->prev = previousNode;
		previousNode->next = newNode;
		newNode->next = NULL;
		previousNode = newNode;
		i++;
		//print frequency of each character
		printf("%c : %d\n", newNode->aNode->character, newNode->aNode->frequency);
	}
	//join the nodes to create the huffman tree
	ChainedNode* currentNode = firstNode;
	ChainedNode* nextInLine = firstNode->next;

	while (currentNode != NULL && nextInLine != NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->left = currentNode->aNode;
		newNode->right = nextInLine->aNode;
		newNode->frequency = newNode->left->frequency + newNode->right->frequency;
		newNode->character = (char)0;

		//insert node at the right place in the tree
		ChainedNode* tmp = currentNode;
		while (tmp->next != NULL && tmp->aNode->frequency < newNode->frequency)
		{
			tmp = tmp->next;
		}
		ChainedNode* insertedNode = malloc(sizeof(ChainedNode));
		insertedNode->aNode = newNode;
		insertedNode->next = tmp->next;
		if (tmp->next != NULL)
		{
			tmp->next->prev = insertedNode;
		}
		tmp->next = insertedNode;
		insertedNode->prev = tmp;
		currentNode = nextInLine->next;
		nextInLine = currentNode->next;
		if (nextInLine == NULL)
		{
			huffmanNode = newNode;
		}

	}

	//Parse the tree and set huffman code for each character
	char code[256] = { 0 };
	parseTree(huffmanNode, code, 0);


	//read the file again and write the huffman code in the output file
	rewind(input);
	int currentBit = 0;
	unsigned char bit = '\0';
	printf("Original : ");

	//save in output file the number of characters in the file
	fputc(huffmanNode->frequency, output);
	fputc('\n', output);

	int notDone = 1;
	saveTree(huffmanNode, output);
	fputc('\n', output);
	while ((current = fgetc(input)) != EOF) {
		//store each character in a bit array using bitmask and bitwise bitshift operation
		char* code = charCoding[(int)current];
		printf("%s", code);
		//shift the bits to the left
		for (int i = 0; i < strlen(code); i++) {
			if (code[i] == '1') {
				bit += 1;
			}
			currentBit++;
			if (currentBit == 8) {
				fputc(bit, output);
				currentBit = 0;
				bit = '\0';
			}
			else
				bit <<= 1;
		}
	}
	if (currentBit != 0) {
		bit <<= 7 - currentBit;
		fputc(bit, output);
	}


	printf("\n\n");

	fclose(input);
	fclose(output);
}


//////////////////////////////////////////
// DECODE HUFFMAN
//////////////////////////////////////////

//Recover the huffman tree from the input file
Node* recoverTree(char* inputFile)
{
	char in = fgetc(inputFile);
	Node* firstNode = malloc(sizeof(Node));
	firstNode->character = '\0';
	firstNode->left = NULL;
	firstNode->right = NULL;
	Node* currentNode = firstNode;
	ChainedNode* firstChainedNode = malloc(sizeof(ChainedNode));
	ChainedNode* currentNullRightNode = firstChainedNode;

	firstChainedNode->aNode = firstNode;
	firstChainedNode->prev = NULL;
	firstChainedNode->next = NULL;
	while (in != '\n')
	{
		in = fgetc(inputFile);
		if (in == '\r' || in == '\n')
			continue;
		Node* newNode = malloc(sizeof(Node));
		newNode->left = NULL;
		newNode->right = NULL;

		ChainedNode* tmp = malloc(sizeof(ChainedNode));
		tmp->aNode = newNode;
		currentNullRightNode->next = tmp;
		tmp->prev = currentNullRightNode;
		tmp->next = NULL;

		if (currentNode->left == NULL)
		{
			currentNode->left = newNode;
		}
		else if (currentNode->right == NULL)
		{
			currentNode->right = newNode;
		}
		else
		{
			while (currentNullRightNode != NULL && currentNullRightNode->aNode->right != NULL)
			{
				ChainedNode* tmp = currentNullRightNode->prev;
				if (tmp != NULL) {
					free(currentNullRightNode);
					currentNullRightNode = tmp;
				}
				else
					break;
			}
			if (currentNullRightNode != NULL)
			{
				currentNode = currentNullRightNode->aNode;
				currentNode->right = newNode;
				currentNullRightNode->next = tmp;
				tmp->prev = currentNullRightNode;
				tmp->next = NULL;
			}
			/*if (currentNullRightNode != NULL) {
				ChainedNode* tmp = malloc(sizeof(ChainedNode));
				currentNullRightNode->next = tmp;
				tmp->prev = currentNullRightNode;
				currentNullRightNode = tmp;
				currentNullRightNode->aNode = currentNode;
			}*/

		}

		if (in == '0')
		{
			in = fgetc(inputFile);
			newNode->character = in;
			newNode->left = 0;
			newNode->right = 0;
		}
		else {
			currentNode = newNode;
			currentNullRightNode = currentNullRightNode->next;
			
		}
		
	}
	return firstNode;
}

//Decode the file using huffman algorithm
void decodeHuffman(char* inputFile)
{
	//read the file in binary mode
	FILE* input = fopen(inputFile, "rb");
	if (input == NULL) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	//get the number of characters in the file
	int nbChar = fgetc(input);
	//skip the newline character
	char c = fgetc(input);
	c = fgetc(input);
	//recover the huffman tree from the file
	Node* recoveredHuffmanTree = recoverTree(input);
	//Create a char array of the size of the file
	char* buffer = malloc(nbChar * 8);
	
	//read the file 
	unsigned char current;
	int count = 0;
	Node* currentNode = recoveredHuffmanTree;
	int written = 0;
	for (int i = 0; i < nbChar; i++) {
		//read the file byte by byte
		fread(&current, 1, 1, input);
		for (int j = 0; j < 8; j++) {
			//if the most significant bit is 1, go right, else go left
			if ((current & 0x80) == 0x80) {
				buffer[count++] = '1';
				currentNode = currentNode->right;
			}
			else {
				buffer[count++] = '0';
				currentNode = currentNode->left;
			}
			current <<= 1;
			//if we reach a leaf, print the character and reset the current node to the root
			if (currentNode->left == NULL && currentNode->right == NULL) {
				printf("%c", currentNode->character);
				currentNode = recoveredHuffmanTree;
				written++;
				if (written == nbChar)
				{
					i = written;
					break;
				}
			}
		}

	}
	printf("\n\nSaved one : ");

	//print the buffer
	for (int i = 0; i < count; i++) {
		printf("%c", buffer[i]);
	}
}


int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("Utilisation : %s <encode|decode|encodeBits|decodebits> <inputFile> <outputFile>\n", argv[0]);
		return EXIT_FAILURE;
	}

	//Huffman encoding
	if (strcmp(argv[1], "encode") == 0) {
		encodeHuffman(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "decode") == 0) {
		decodeHuffman(argv[2]);
	}
	else {
		printf("Utilisation : %s <encode|decode|encodeBits|decodebits> <inputFile> <outputFile>\n", argv[0]);
		return EXIT_FAILURE;
	}
}