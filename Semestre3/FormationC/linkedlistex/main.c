#include "list.h"


int main(){
    List my_list = new_list();
    print_list(my_list);
    my_list = push_front_list(my_list, 5);
    my_list = push_back_list(my_list, 6);
    print_list(my_list);
    //my_list = pop_back_list(my_list);
    //my_list = pop_front_list(my_list);
    my_list = clear_list(my_list);
    print_list(my_list);

    
}

