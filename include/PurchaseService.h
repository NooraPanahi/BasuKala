#ifndef PURCHASE_SERVICE_H
#define PURCHASE_SERVICE_H

#include "data_structures/Hash/UserHashTable.h"
#include "PurchaseHistory.h"
#include "Basket.h"
#include "Order.h"

class PurchaseService{
    private:
        UserHashTable users;
        User* currentUser;
        Basket currentBasket;
        int nextOrderId;
    public:
        PurchaseService();
        bool registerUser(int id, const std::string& name, double balance);
        bool login(const std::string& name);
        void logout();

        void addToBasket(int productId, double price);
        bool removeFromBasket(int index);
        void veiwBasket() const;

        bool checkout(int cityId, long long timestamp);
        void showPurchaseHistory() const;
};

#endif