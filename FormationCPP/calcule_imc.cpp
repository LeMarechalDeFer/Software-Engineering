#include <iostream>

int main(){
    float poids_kg {};
    float taille_cm {} ;
    float taille_m{} ;
    float imc {} ;
    std::cout << "Donne moi ton poids (en kg) et ta taille (en cm)" << std::endl ;
    std::cout << "Ton poids : " ; 
    std::cin >> poids_kg;
    if(poids_kg <= 0){
        std::cerr << "Ton poids doit être positif" << std::endl ;
        return EXIT_FAILURE ;
    }


    std::cout << "Ta taille : " ; 
    std::cin >> taille_cm;
    if(taille_cm <= 0){
        std::cerr << "Ta taille doit être positif" << std::endl ;
        return EXIT_FAILURE ;
    }

    std::cout << "Tu as rentré :" << poids_kg << "kg et " << taille_cm << "cm." << std::endl;

    taille_m = taille_cm /100.0 ;


    imc = poids_kg / (taille_m * taille_m);

    if(imc >= 30){
        std::cout << "Votre imc est " << imc << ", Vous etes en obésité." << std::endl ;
        return EXIT_SUCCESS ;
    }
    else if(imc >= 25){
        std::cout << "Votre imc est " << imc << ", Vous etes en surpoids." << std::endl ;
        return EXIT_SUCCESS ;
    }
    else if(imc >= 18.5){
        std::cout << "Votre imc est " << imc << ", Vous etes en poids normal." << std::endl ;
        return EXIT_SUCCESS ;
    }
    else{
        std::cout << "Votre imc est " << imc << ", Vous etes en sous poids." << std::endl ;
        return EXIT_SUCCESS ;
    }
    

    return EXIT_FAILURE;

    
}   