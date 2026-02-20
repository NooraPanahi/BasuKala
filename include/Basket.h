#ifndef BASKET_H
#define BASKET_H

#include <vector>
#include "../data_structures/Stack/ItemStack.h"

struct Item {
    int productId;
    double price; 
    Item(int id , double p) : productId(id), price(p) {} 
};

class Basket{
    private:
        std::vector<Item> cart;
        ItemStack removedStack;
        double totalPrice;
    public:
        Basket();
        void addProduct(int productId, double price);
        bool removeProductByIndex(int index);
        bool undoLastRemovedItem();
        void clear();
        double getTotalPrice()const;
        const std::vector<Item>&  getProducts()const;
        bool isEmpty()const;
        int size()const;
};

#endif