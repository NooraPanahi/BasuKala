#ifndef STACK_H
#define STACK_H

#include "Product.h"

class ItemStack{
    private:
        struct Node{
            Product data;
            Node* next;
            Node(const Product& item) : data(item), next(nullptr){}
        };
        Node* node;
    public:
        ItemStack();
        ~ItemStack();
        void push(const Product& item);
        bool pop(Product& removedItem);
        bool isEmpty()const;
};



#endif