#include <stdio.h>

void DEPLACER(char X, char Y) {
    printf("Déplacer le disque de %c vers %c\n", X, Y);
}

void HANOI(int N, char A, char B, char C) {
    if (N == 1) {
        DEPLACER(A, C); // Ici, on déplace directement de A à C pour le dernier disque
    } else {
        HANOI(N-1, A, C, B); // Déplacer N-1 disques de A vers B en utilisant C comme intermédiaire
        DEPLACER(A, C); // Déplacer le plus grand disque de A vers C
        HANOI(N-1, B, A, C); // Déplacer les N-1 disques de B vers C en utilisant A comme intermédiaire
    }
}

int main() {
    int N = 3; // Exemple pour 3 disques
    HANOI(N, 'A', 'B', 'C');
    return 0;
}
