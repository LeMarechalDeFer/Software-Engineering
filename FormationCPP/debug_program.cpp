/*
ASSERTION (pour les erreurs dev):
Les assertions <cassert> donne accès à la macro assert
assert(<expression> && message_d'echec), 
==> permet d'éviter les erreurs devlopment combiné avec le -g

==> en production, pour supprimer les assertions utiliser -DNDEBUG dans la compilation

*/

// #include <iostream> 
// #include <cassert>
// #include <string>


// void createPlayer(std::string name, int level){

//     assert(level > 0 && "Le niveau doit être supérieur à 0.");
//     std::cout << "Le personnage " << name << " vient d'apparaitre avec le level " << level << std::endl ;

// }

// int main(){
    
//     createPlayer("Romain", -5);
//     return EXIT_SUCCESS;

// }


/*
EXCEPTION (pour les erreurs user):
- utiliser soit le type précis de l'exception possible, soit le type générique sinon.
- doit être passé par référence
- peux être cumulé avec plusieurs catch d'affilé, mettre le générique en dernier.

- une exception peut être levée avec throw
- lever une exception signifie allez directement dans le bloc catch visé

*/

#include <iostream> 
#include <string>
#include <exception>


int main(){
    // throw std::invalid_argument("Pas le bon argument");

    try{
        //code generant une exception/ code sensible

        throw std::invalid_argument("Pas le bon argument");
    }
    catch(const std::invalid_argument& err){
        std::cout << err.what() << std::endl ;
    }
    catch(const std::exception& err){
        std::cout << "Une erreur s'est produite." << std::endl ;
    }
}


/*

goodbit : 1
failbit : 0
badbit :  0

*/

// int main(){
//     // std::cout << "Hello Word !\n" << "How are You" <<std::endl;
//     // std::cout << "Bye !" ;


//     std::cout << "Good: " << std::cin.good() << std::endl ; 
//     std::cout << "Fail: " << std::cin.fail() << std::endl ; 
//     std::cout << "Bad: " << std::cin.bad() << std::endl; 

//     int number{} ;
//     std::cin >> number ; 
//     std::cout << "Nombre saisie" << number << std::endl ;

//     std::cout << "Good: " << std::cin.good() << std::endl ; 
//     std::cout << "Fail: " << std::cin.fail() << std::endl ; 
//     std::cout << "Bad: " << std::cin.bad() << std::endl; 

//     //si cin est à l'etat d'erreur on peut le reinitialisé 

//     std::cin.clear();
//     std::cout << "Apres netoyage de l'erreur \n"  ;

//     std::cout << "Good: " << std::cin.good() << std::endl ; 
//     std::cout << "Fail: " << std::cin.fail() << std::endl ; 
//     std::cout << "Bad: " << std::cin.bad() << std::endl; 
    

//     return 0 ; 
// }