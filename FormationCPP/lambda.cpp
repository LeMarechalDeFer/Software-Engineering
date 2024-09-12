/*

Une lambda est une focntion : 
- très courte
- pas forcement de nom
- peut être affecté à une variable
- obligatoirement commence par auto 
de cette manière : []() <spécificateur> -> <type_retour> {} <<   (la porté de la variable est locale)

pattern/bloc de code qui n'a pas accès au variable parents par defaut [] sinon deux possibilités :
() : mettre des varaibles dans les argc
[] : capturer des varibles : 
- [=]() -> totalité des variables externes en lectures seule (immuable)
- [=]() mutable -> totalité des variable externe en lecture et ecriture interne (copie)
- [&]() mutable -> totalité des variable externe en lecture et ecriture 
- &var =var pour spécifier, ou par exemple  (=, &var)
- voir la varaible noexcept plus tard


#include <iostream>

int main(){
    auto func = []() -> void{ std::cout << "Hello word !" << std::endl; }; 

    func();

    return EXIT_SUCCESS;
}

*/

/*

Exercice : Gestion d'une collection de données avec des lambdas
Objectifs :
Utiliser une lambda pour filtrer des éléments dans une collection.
Utiliser une lambda pour trier des éléments d'une collection.
Manipuler une lambda qui capture des variables externes pour effectuer un calcul cumulatif sur une collection de données.
Consignes :
Créer une collection de nombres :
Déclare un std::vector<int> contenant une dizaine de nombres aléatoires.

Filtrage avec une lambda :
Crée une lambda qui filtre les nombres impairs. Parcours ta collection et utilise cette lambda pour créer un nouveau std::vector<int> qui ne contiendra que les nombres pairs.

Trier les nombres avec une lambda :
Utilise une lambda pour trier ce nouveau std::vector<int> (celui contenant uniquement les nombres pairs) dans l'ordre décroissant.

Calcul cumulatif avec une lambda :
Crée une autre lambda qui capture une variable somme par référence. Utilise cette lambda pour parcourir ton std::vector<int> trié et additionner chaque élément à somme. Affiche ensuite la somme totale.

Résultats attendus :
Tu auras filtré les nombres pairs, les auras triés dans l'ordre décroissant, puis tu auras calculé la somme de ces nombres avec une lambda qui capture une variable externe.
Astuces (sans squelette) :
Utilise des fonctions comme std::copy_if pour filtrer.
Utilise std::sort avec une lambda pour trier.
Utilise une boucle ou un algorithme comme std::for_each avec une lambda pour calculer la somme.
*/

//exercice 1 
// #include <iostream>

// int main(){

//     int a{};
//     int b{};

//     std::cout << "Donne deux nombres a et b : " << std::endl;
//     std::cin >> a >> b ; 

//     auto func = [](int a, int b) -> int {  
//         return a+b ;
//    } ; 

//     std::cout << "La reponse est :" << func(a, b) << std::endl ;
//     return EXIT_SUCCESS;
// }


//exercice 2

#include <iostream>

