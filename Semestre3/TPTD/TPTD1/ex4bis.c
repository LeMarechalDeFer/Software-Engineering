#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_TAB 10
#define NOMBRE_MAX 20



void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *tab, int low, int high){
    int pivot = tab[high] ; //select the righmost element as pivos
    int i = (low-1); //pointer for greater element

  // traverse each element of the array compare them with the pivot
  for (int j = low; j < high; j++) {
    if (tab[j] <= pivot) {
        
      i++; // if element smaller than pivot is found swap it with the greater element pointed by i
      swap(&tab[i], &tab[j]); // swap element at i with element at j
    }
  }

  swap(&tab[i + 1], &tab[high]); // swap the pivot element with the greater element at i
  
  return (i + 1);  // return the partition point

}

void QuickSort(int *tab, int low, int high){
  if(low<high){
  int pivot = partition(tab, low, high);
  
  QuickSort(tab, low, pivot-1);
  QuickSort(tab, pivot+1, high);
  }
  
}

void QuickSort2D(int **tab, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        QuickSort(tab[i], 0, cols - 1);
    }
}


int DICHREC(int *tab, int low, int high, int x) {
    if (low <= high) {
        int mid = (low + (high - low) / 2);

        if (tab[mid] == x) {
            return mid;
        }

        if (tab[mid] > x) {
            return DICHREC(tab, low, mid - 1, x);
        } else {
            return DICHREC(tab, mid + 1, high, x);
        }
    } else {
        return -1;
    }
}

void DICHREC2D(int **tab, int rows, int cols, int x) {
    for (int i = 0; i < rows; i++) {
        int index = DICHREC(tab[i], 0, cols - 1, x);
        if (index != -1) {
            printf("Element %d trouvé à la ligne %d, colonne %d\n", x, i, index);
        } else {
            printf("Element %d non trouvé dans la ligne %d\n", x, i);
        }
    }
}



int main(){
    srand(time(NULL));
    int **tab = (int**)malloc(sizeof(int*)*TAILLE_TAB);
    
    int x = 8;
    int i, j ;

    for (i = 0; i < TAILLE_TAB; i++) {
        tab[i] = (int*)malloc(sizeof(int) * TAILLE_TAB);
    }

    for(i=0; i<TAILLE_TAB; i++){
        for(j=0; j<TAILLE_TAB; j++){
            tab[i][j] = rand()%NOMBRE_MAX ;
        }
    }

    QuickSort2D(tab, TAILLE_TAB, TAILLE_TAB);

    for(i=0; i<TAILLE_TAB; i++){
        for(j=0; j<TAILLE_TAB; j++){
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }

    DICHREC2D(tab, TAILLE_TAB, TAILLE_TAB, x);

    for (i = 0; i < TAILLE_TAB; i++) {
        free(tab[i]);
    }

    free(tab);

}