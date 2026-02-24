#ifndef BASUKALA_H
#define BASUKALA_H
#include "../include/PurchaseService.h"
#include "../include/services/ProductService.h"
#include <iostream>

class BasuKala{
    private:
        PurchaseService Purchase;
        PService pservice;
    public:
        BasuKala();
        bool firstPage();
        bool secondPageNormal();
        void run();
};

#endif