#ifndef EXERCICE_H
#define EXERCICE_H

#include <stdio.h>
#include <stdlib.h>

char **lecturegraphe(int *ordre);

void affichematrice(int ordre, char **adjacence);

void affichesuccesseurs(int ordre, char **adjacence);

void affichepredecesseurs(int ordre, char **adjacence);

void affichesarcs(int ordre, char **adjacence);

void saisiegraphe();

int nbchemin2(int ordre, char **adjacence);

#endif 
