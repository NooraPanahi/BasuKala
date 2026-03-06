#ifndef BASKET_H
#define BASKET_H

#include <vector>
#include "Product.h"
#include "data_structures/Stack/ItemStack.h"

class Basket{
    private:
        std::vector<Product> cart;
        ItemStack removedStack;
        double totalPrice;
    public:
        Basket();
        void addProduct(const Product& product);
        bool removeProductByIndex(int index);
        bool undoLastRemovedItem();
        void clear();
        double getTotalPrice()const;
        const std::vector<Product>&  getProducts()const;
        bool isEmpty()const;
};

#endif