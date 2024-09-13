#include <iostream>

/*
copie != pointeur != reference

une reference est un alias :
- ne peut pas être vide ;
- sera toujours le même ==> !! n'est pas actualisé, c'est une constante qui garde la valeur à laquel on la initialisé
- se fait avec &VARIABLE{variable_reference}


surcharge de fonctions :
Surcharge : même nom de fonction, signatures différentes (types ou nombre de paramètres)
Le compilateur choisit la version selon les arguments passés
Le type de retour seul ne permet pas de différencier les surcharges
Utilisée pour rendre le code plus flexible et lisible



*/

//enumération (porté globale)
enum NaturalElement{
    earth, //1
    air,   //2 ect car incrementé de 1 par rapport au premier.
    fire,
    water
} ;

// utilisation : NaturalElement ne{fire} 

//énumeration étendue
enum class NaturalElement{
    earth, //1
    air,   //2 ect car incrementé de 1 par rapport au premier.
    fire,
    water
} ;

// utilisation : NaturalElement ne{NaturalElement::fire} 



// //reférence &
// int sum(int& a, int& b){
//     return a+b ;
// }


// surcharge de fonction
int sum(int a, int b){
    return a+b ;
}

float sum(float a, float b){
    return a+b ;
}



//auto est un type deduit
//on evite la surcharge en utilisant une templates generique de type deduit
auto sum(auto a, auto b){
    return a+b ;
}

int main(){


    int a{5} ;
    int b{12} ;

    std::cout << "La somme de 5 et 12 est :" << sum(a, b) << std::endl ;

    return EXIT_SUCCESS;
}