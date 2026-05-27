#ifndef PURCHASE_HISTORY_H
#define PURCHASE_HISTORY_H

#include "Order.h"
#include "../include/services/ProductService.h"
#include <iostream>
class PurchaseHistory{
    private:
        struct Node{
            Order order;
            Node* next;
            Node(const Order & ord) : order(ord), next(nullptr){}
        };
        Node* head;        
        Node* tail;
    public:
        PurchaseHistory();
        ~PurchaseHistory();
        void addOrder(const Order& order);
        void display(PService& pservice)const;
        bool isEmpty()const;
};


#endif