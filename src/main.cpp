#include "../include/PurchaseService.h"
#include <vector>
int main(){
    PurchaseService service;
   if( service.login("noora"))
        std::cout <<  "logged in successfully\n"; 
    else{
        std::cout <<  " no user found\n";
        std::cout << "sign in!! \n";
    }
    service.registerUser(1,"noora",120);
    service.login("noora");
    service.addToBasket(3,6);
    service.veiwBasket();
    std::cout << "-------------\n";
    service.checkout(7,32123);
    service.showPurchaseHistory();
}