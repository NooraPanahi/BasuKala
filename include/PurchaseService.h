#ifndef PURCHASE_SERVICE_H
#define PURCHASE_SERVICE_H

#include "data_structures/Hash/UserHashTable.h"
#include "PurchaseHistory.h"
#include "Basket.h"
#include <unordered_map>
#include "Order.h"
#include <memory>


class PurchaseService{
    private:
        UserHashTable users;
        User* currentUser;
        Basket currentBasket;
        int nextOrderId;
        int nextUserId = 1;
        long long nextTimestamp = 1;
        std::unordered_map<int, User*> usersById;
    public:
        PurchaseService();
        bool registerUser(Role role, const std::string& name, double balance);
        bool login(const std::string& name);
        void logout();
        User* user_getter(int id) const;
        void addToBasket(const Product& product);
        bool removeFromBasket(int index);
        bool CheckIfBasketExists() const;
        void showAllUsers()const;
        Order checkout(int cityId);
        void showPurchaseHistory() const;
        bool userExists(const std::string& name);
        Role getUsersRole()const;
        User* getCurrentUser()const;
        Basket& getCurrentBasket();
};

#endif