/*
code sensible à la casse Toi != toi != TOI (cpp en est un)
code non sensible à la casse : Toi = toi = TOI

std::endl : Retour à la ligne + vidange du flux.

Les sorties (ex: std::cout) utilisent un buffer (mémoire tampon) pour améliorer les performances.
Le buffer stocke temporairement les données avant de les envoyer à la destination (écran, fichier, etc.).
Le flush force l'envoi immédiat des données du buffer, utile pour s'assurer que l'affichage est visible
instantanément ou que les données sont enregistrées en cas de crash.

En C++, plusieurs flux de sortie existent pour différents usages :
1. std::cout : Sortie standard bufferisé pour afficher des informations à l'écran.
2. std::cerr : Sortie d'erreur (standard) non-bufferisée, utilisée pour afficher les messages d'erreur immédiatement. 
3. std::clog : Sortie d'erreur (journalisé) bufferisée, utilisée pour des messages de log. Les sorties ne sont pas immédiates.
std::endl ajoute un retour à la ligne et force un flush du flux (cout, cerr, clog).

std::cout est bufferisé : les données sont stockées temporairement avant d'être affichées.
Un flush explicite (ex: std::endl ou std::flush) force l'affichage immédiat.

buffer = mémoire tempon
\t = retour à la ligne
\\ = afficher un antislash
le flush à un cout donc parfois plus interessant \n que endl

buffer lecture d'entrée :

introduction de la porté de la communication d'un code au sein meme d'une fonction avec les blocs de code (contexte) : {}
bloc enfants et bloc parents 
- 

*/


#include <iostream> 

int main(){
    // std::cout << "Hello Word !\n" << "How are You" <<std::endl;
    // std::cout << "Bye !" ;


    std::cout << "Good: " << std::cin.good() << std::endl ; 
    std::cout << "Fail: " << std::cin.fail() << std::endl ; 
    std::cout << "Bad: " << std::cin.bad() << std::endl; 

    int number1{} ;
    std::cin >> number1 ; 
    std::cout << "Nombre saisie1" << number1 << std::endl ;

    int number2{} ;
    std::cin >> number2 ; 
    std::cout << "Nombre saisie2" << number2 << std::endl ;

    // std::cin.ignore(255, '\n');

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