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





int main(){
  srand(time(NULL));
  int *tab = (int*)malloc(sizeof(*tab)*TAILLE_TAB);
  int i ;
  int x = 7 ;
  
  for(i=0; i<TAILLE_TAB; i++){
      tab[i] = rand()%NOMBRE_MAX ;
  }

  QuickSort(tab, 0, TAILLE_TAB-1);

  for(i=0; i<TAILLE_TAB; i++){
      printf("Numero %d : %d\n", (i+1), tab[i]);
  }

  int index = DICHREC(tab, 0, TAILLE_TAB - 1, x);

  if (index != -1){
    printf("Element trouvé à l'index : %d\n", index + 1); // +1 pour ajuster l'index base 0 en base 1
  }
  else{
    printf("Element non trouvé dans le tableau\n");
  }

  free(tab);

}