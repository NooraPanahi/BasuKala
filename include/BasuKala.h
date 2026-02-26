#ifndef BASUKALA_H
#define BASUKALA_H
#include "../include/PurchaseService.h"
#include "../include/services/ProductService.h"
#include "../include/data_structures/graph.h"
#include "../include/services/DeliveryService.h"

#include <iostream>

class BasuKala{
    private:
        PurchaseService Purchase;
        PService pservice;
        Graph graph;
        DelivaryService delivery;
    
    public:
        BasuKala();
        void completePurchase();
        bool signUp();
        bool login();
        void increaseBalance();
        bool showCategories();
        void search();
        void editCart();
        bool firstPage();
        bool secondPageNormal();
        void normalMenu();
        void adminMenu();
        void Logout();
        void addProductAdmin();
        void removeProductAdmin();
        void deliverOrders();
        void undolastremoveditem();
        bool storePageNormal();
        void ChooseItem();
        void run();
};

#endif