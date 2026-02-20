#include "../include/Basket.h"

Basket::Basket() : totalPrice(0.0){}

void Basket::addProduct(int productId, double price){
    cart.emplace_back(productId, price);
    totalPrice += price;
}
bool Basket::removeProductByIndex(int index){
    if(index < 0 || index >= static_cast<int>(cart.size()))
        return false;
    removedStack.push(cart[index]);
    totalPrice -= cart[index].price;
    cart.erase(cart.begin() + index);

    return true;
}
bool Basket::undoLastRemovedItem(){
    Item lastItem(0,0);
    if(!removedStack.pop(lastItem)) return false;

    cart.push_back(lastItem);
    totalPrice += lastItem.price;
    return true;
}
void Basket::clear(){
    cart.clear();
    totalPrice = 0.0;
    while (!removedStack.isEmpty()){
        Item i(0,0);
        removedStack.pop(i);
    }  
}

double Basket::getTotalPrice() const{
    return totalPrice;
}

const std::vector<Item> &Basket::getProducts() const{
    return cart;
}

bool Basket::isEmpty() const{
    return cart.empty();
}

int Basket::size() const{
    return static_cast<int>(cart.size());
}
