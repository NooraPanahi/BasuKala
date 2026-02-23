#include "../include/Basket.h"

Basket::Basket() : totalPrice(0.0){}

void Basket::addProduct(const Product& product){
    cart.push_back(product);
    totalPrice += product.getPrice();
}
bool Basket::removeProductByIndex(int index){
    if(index < 0 || index >= static_cast<int>(cart.size()))
        return false;
    removedStack.push(cart[index]);
    totalPrice -= cart[index].getPrice();
    cart.erase(cart.begin() + index);

    return true;
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

int Basket::size() const{
    return static_cast<int>(cart.size());
}
