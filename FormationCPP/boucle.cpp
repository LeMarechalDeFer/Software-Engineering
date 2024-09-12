#include <iostream>
#include <string>


// for (declaration : collection) {
//     // Code à exécuter pour chaque élément
// }

//le deux points parcours la collection

int main(){
    std::string sentence {"Hello world, how are you ?"} ;

    //meme programme

    // for(const auto letter : sentence ){
    //     std::cout << letter << '\n' ;
    // }

    for (size_t i = 0; i < sentence.size(); ++i) {
    char letter = sentence[i];
    std::cout << letter << '\n';
    }


   

    return EXIT_SUCCESS; 
    
}