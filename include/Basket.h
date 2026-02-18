#ifndef BASKET_H
#define BASKET_H

#include <vector>

struct Item {
    int productId;
    double price; 
    Item(int id , double p) : productId(id), price(p) {} 
};

class Basket{
    private:
        std::vector<Item> cart;
        double totalPrice;
    public:
        Basket();
        void addProduct(int productId, double price);
        bool removeProductByIndex(int index);
        void clear();
        double getTotalPrice()const;
        const std::vector<Item>&  getProducts()const;
        bool isEmpty()const;
        int size()const;
};

#endif