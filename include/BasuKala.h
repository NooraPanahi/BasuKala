#ifndef BASUKALA_H
#define BASUKALA_H
#include "../include/PurchaseService.h"
#include "../include/services/ProductService.h"
#include "../include/data_structures/Trie/Trie.h"
#include <iostream>

class BasuKala{
    private:
        PurchaseService Purchase;
        PService pservice;
        Trie trie;
    public:
        BasuKala();
        bool firstPage();
        bool secondPageNormal();
        bool storePageNormal();
        void run();
};

#endif