#include <iostream>

int main(){
    float poids_kg {};
    float taille_cm {} ;
    float imc {} ;
    std::cout << "Donne moi ton poids (en kg) et ta taille (en cm)" << std::endl ;
    std::cout << "Ton poids : " ; 
    std::cin >> poids_kg;

    std::cout << "Ta taille : " ; 
    std::cin >> taille_cm;


    std::cout << "Tu as rentré :" << poids_kg << " et " << taille_cm << std::endl;

    std::cout << imc << std::endl ;
    return EXIT_SUCCESS;

    
}   