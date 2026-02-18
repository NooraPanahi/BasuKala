#include "../include/data_structures/Hash/UserHashTable.h"
#include <iostream>
int main(){
    UserHashTable users;
    users.insert(User(1, "Ali" , 100 , 0));
    users.insert(User(2 , "ali", 200, 0));

    if( users.exists("Alii"))
        std::cout << "yes\n";
    else
        std::cout << "no\n";
}