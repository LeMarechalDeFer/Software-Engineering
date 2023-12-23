//Stucture géométirique en C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define Pi 3.141592653589793 

typedef struct Point {
    float x;
    float y;
} Point;

typedef struct Rectangle {
    Point p1;
    Point p2;
} Rectangle;

typedef struct Cercle {
    Point centre;
    float rayon;
} Cercle;


float distance_euclidienne(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

float aireRectangle(Rectangle r) {
    float dx = fabs(r.p1.x - r.p2.x);
    float dy = fabs(r.p1.y - r.p2.y);
    return dx*dy;
}

float aireCercle(Cercle c) {
    float r = c.rayon;
    float aire = Pi * r * r;
    return aire;
}

float perimetreCercle(Cercle c) {
    float r = c.rayon;
    float perimetre = 2 * Pi * r;
    return perimetre;
}

bool croisement_entre_2_Rectangles(Rectangle r1, Rectangle r2){
    // Verifier l'abscisse
    if(r1.p1.x > r2.p2.x || r2.p1.x > r1.p2.x) {
        return false;
    }
    //Verifier l'ordonnée
    if(r1.p1.y > r2.p2.y || r2.p1.y > r1.p2.y) {
        return false;
    }
    return true;
}

bool croisement_entre_Rectangle_Cercle(Rectangle r, Cercle c){
    float dx = fabs(c.centre.x - r.p1.x);
    float dy = fabs(c.centre.y - r.p1.y);
    // Verifier l'abscisse
    if(dx > (r.p2.x - r.p1.x + c.rayon)) {
        return false;
    }
    //Verifier l'ordonnée
    if(dy > (r.p2.y - r.p1.y + c.rayon)) {
        return false;
    }
    // Verifier si le cercle est dans le rectangle
    if(dx <= (r.p2.x - r.p1.x)) {
        return true;
    }
    if(dy <= (r.p2.y - r.p1.y)) {
        return true;
    }
    // Verifier si le cercle touche un coin du rectangle
    float dx2 = dx - (r.p2.x - r.p1.x);
    float dy2 = dy - (r.p2.y - r.p1.y);
    return (dx2*dx2 + dy2*dy2 <= (c.rayon*c.rayon));
    
}

int main(){
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 5};
    Point p4 = {6, 6};
    Rectangle r = {p1, p2};
    Rectangle r2 = {p3, p4};
    Cercle c = {p1, 2};
    

    printf("Distance euclidienne entre p1 et p2 : %f\n", distance_euclidienne(p1, p2));   
    printf("Aire du rectangle : %f\n", aireRectangle(r));   
    printf("Aire du cercle : %f\n", aireCercle(c));
    printf("Perimetre du cercle : %f\n", perimetreCercle(c)); 
    printf("Croisement entre 2 rectangles : %d\n", croisement_entre_2_Rectangles(r, r2));
    printf("Croisement entre rectangle et cercle : %d\n", croisement_entre_Rectangle_Cercle(r, c));
    return 0;
}

