#include "../include/Basket.h"
#include <iostream>

int main(){
    Basket basket;
    basket.addProduct(1 , 56.8);
    basket.addProduct(2, 32.4);
    std::cout << "total price: " << basket.getTotalPrice() << std::endl;

   if(basket.removeProductByIndex(1))  //remember: starting from 0
    std::cout << "total price after removing product 2 : " << basket.getTotalPrice();
    
    std::cout << "\nYour products are:\n";
    for(auto i : basket.getProducts())
        std::cout << "product id: " << i.productId << " price: " << i.price << '\n'; 
}