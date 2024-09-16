#include "point.hpp"


//exemple de constructeur 
Point::Point(){
    std::cout << "création d'un point !" << this << std::endl ;
}

//exemple de destructeur
Point::~Point()
{
    std::cout << "destruction d'un points !" << this << std::endl ;
}
