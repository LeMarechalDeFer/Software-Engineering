/*

struct : données public (par defaut)
class : données privées (par defaut)

Niveaux d'accès : public, private, protected
 
dans une class il y a un :
- constructeur (par defaut c'est lorsque l'on ne renseigne aucune information) (forcement public)  
- destructeur (par defaut)


L'instance courante ("this"), permet d'indiquer l'adresse de reference de l'objets

On peut aussi faire un 
- un construction par copie
- un constructeur de déplacement
- un destructeur
mettre  = defaut, delete ect pour dire au ciompilateur ce q'uil doit implicitement dire.

un attibut est un variable dans une class (poo)
une methode est une fonction dans une class (poo)

on peut construire autant de constructeur que l'on veut dans une class meme s'ils ont le même nom, du moment qu'ils ont une signature différente
 
*/
#include "point.hpp"

int main(){
    Point p{};

    return 0;
}