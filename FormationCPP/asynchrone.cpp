#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);  // Désactive la synchronisation avec les flux C
    std::cout << "Entrez votre nom : ";  // Ce texte pourrait ne pas apparaître immédiatement
    std::string name;
    std::cin >> name;  // Pas de flush automatique ici
    std::cout << "Bonjour, " << name << "!" << std::endl;
    return 0;
}
