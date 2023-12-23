# Nom du fichier exécutable
TARGET = exercice1

# Compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g 

# Dépendances (headers)
DEPS = binaryTree1.h

# Objets
OBJ = binaryTree1.o main.o

# Règle pour générer les fichiers objets (.o)
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Règle principale
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET)

# Déclaration des cibles qui ne correspondent pas à des fichiers
.PHONY: clean
