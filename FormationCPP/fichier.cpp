#include <iostream>
#include <fstream>


int main(){
     
    std::ifstream f{"animals.txt"} ;
    std::string name{"MDR"};
    std::string namevoid{"222"};
    if(f.is_open()){
        


        f >> namevoid;
        std::cout << namevoid << std::endl ;

    }


    

    return 0;
}