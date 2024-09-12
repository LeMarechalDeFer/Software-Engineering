/*


goodbit : 1
failbit : 0
badbit :  0

*/




#include <iostream> 

int main(){
    // std::cout << "Hello Word !\n" << "How are You" <<std::endl;
    // std::cout << "Bye !" ;


    std::cout << "Good: " << std::cin.good() << std::endl ; 
    std::cout << "Fail: " << std::cin.fail() << std::endl ; 
    std::cout << "Bad: " << std::cin.bad() << std::endl; 

    int number{} ;
    std::cin >> number ; 
    std::cout << "Nombre saisie" << number << std::endl ;

    std::cout << "Good: " << std::cin.good() << std::endl ; 
    std::cout << "Fail: " << std::cin.fail() << std::endl ; 
    std::cout << "Bad: " << std::cin.bad() << std::endl; 

    //si cin est à l'etat d'erreur on peut le reinitialisé 

    std::cin.clear();
    std::cout << "Apres netoyage de l'erreur \n"  ;

    std::cout << "Good: " << std::cin.good() << std::endl ; 
    std::cout << "Fail: " << std::cin.fail() << std::endl ; 
    std::cout << "Bad: " << std::cin.bad() << std::endl; 
    

    return 0 ; 
}