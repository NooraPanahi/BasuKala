#include "../include/Basket.h"

Basket::Basket() : totalPrice(0.0){}

void Basket::addProduct(int productId, double price){
    cart.emplace_back(productId, price);
    totalPrice += price;
}
bool Basket::removeProductByIndex(int index)
{
    if(index < 0 || index >= static_cast<int>(cart.size()))
        return false;
    totalPrice -= cart[index].price;
    cart.erase(cart.begin() + index);

    return true;
}
void Basket::clear(){
    cart.clear();
    totalPrice = 0.0;
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
