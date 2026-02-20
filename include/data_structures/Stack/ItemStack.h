#ifndef STACK_H
#define STACK_H

#include "../Basket.h"

class ItemStack{
    private:
        struct Node{
            Item data;
            Node* next;
            Node(const Item& item) : data(data), next(nullptr){}
        };
        Node* node;
    public:
        ItemStack();
        ~ItemStack();
        void push(const Item& item);
        bool pop(Item& removedItem);
        bool isEmpty()const;
};



#endif