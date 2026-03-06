#include "../include/Basket.h"

Basket::Basket() : totalPrice(0.0){}

void Basket::addProduct(const Product& product){
    cart.push_back(product);
    totalPrice += product.getPrice();
}
bool Basket::removeProductByIndex(int id){
    
    for(int i = 0; i < static_cast<int>(cart.size()); i++){
        if(cart[i].getId() == id){
            removedStack.push(cart[i]);
            totalPrice -= cart[i].getPrice();
            cart.erase(cart.begin()+i);
            return true;
        }
    }
    return false;
}
bool Basket::undoLastRemovedItem(){
    Product lastItem(0,0,"",0);
    if(!removedStack.pop(lastItem)) return false;

    cart.push_back(lastItem);
    totalPrice += lastItem.getPrice();
    return true;
}
void Basket::clear(){
    cart.clear();
    totalPrice = 0.0;
    while (!removedStack.isEmpty()){
        Product i(0,0,"",0);
        removedStack.pop(i);
    }  
}

double Basket::getTotalPrice() const{
    return totalPrice;
}

const std::vector<Product> &Basket::getProducts() const{
    return cart;
}

bool Basket::isEmpty() const{
    return cart.empty();
}

