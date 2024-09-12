
/*
Rappel :
- unsigned XXX = seulement les positifs
- float 4 octets et double 8 octets
- une information qui n'a pas lieu de changer dnas un programme peux etre mis en "const" (lecture seule)
*/

/*

auto : le complilateur peux detecter le type de la variable optimal

mettre {} derrière une variable l'initialise par defaut
on utilise le point et non la virgule

suffixe à connaitre:
- u, U (non signé)
- f, F (flottant)
- l, L (long int, long double)
- ll, LL (long long int)

Prefixe
- 0b (binaire)
- 0 (octal)
- 0x (hexadécimal)

Possiblité d'utilisé des séparateur pour la lisibilité des grands nombres 12'134'245;

difference entre :
result = data++ donnera l'ancienne valeur de data pour result car post incrementatino
result = --data pre incrementation
using namespaces std::literals  permets  de mettre s derrière une variable 

*/

/*
TO list
- apprendre à utilisé sizeof sur cpp

stuct, class
std::vector, std::array, std::deque
shared memory ou memory-mapped file
std::chrono, std::time, std::tm, unisinged long long,
boost::multipprecision
td::mutex, std::atomic, std::condition_variable

*/

#include <iostream>
#include <string>


int main(){
    
    //unsigned int test= 10 ; 
    
    std::string  hello_word{} ;
    std::getline(std::cin, hello_word);
    std::cout <<"La phrase est : " << hello_word << std::endl ;

    
    return EXIT_SUCCESS;
}