
# Définition du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror 

# Librairies supplémentaires
LIBS = -lm

# Nom de l'exécutable pour exercice1
EXE1 = exercice1

# Nom de l'exécutable principal
MAIN_EXE = main

# Tous les fichiers objets
OBJS = exercice1.o main.o planete.o

# Règle par défaut
all: $(EXE1) $(MAIN_EXE)

# Règles pour construire les exécutables
$(EXE1): exercice1.o
	$(CC) $(CFLAGS) -o $(EXE1) exercice1.o $(LIBS)

$(MAIN_EXE): main.o planete.o
	$(CC) $(CFLAGS) -o $(MAIN_EXE) main.o planete.o

# Règles pour construire les fichiers objets
exercice1.o: exercice1.c
	$(CC) $(CFLAGS) -c exercice1.c

main.o: main.c planete.h
	$(CC) $(CFLAGS) -c main.c

planete.o: planete.c planete.h
	$(CC) $(CFLAGS) -c planete.c

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(EXE1) $(MAIN_EXE) $(OBJS)

# Règle pour exécuter le programme principal
run: $(MAIN_EXE)
	./$(MAIN_EXE)

# Règle pour exécuter l'exercice1
run_ex1: $(EXE1)
	./$(EXE1)

