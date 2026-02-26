#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../include/User.h"

class UserHashTable{
    private:
        struct Node{
            User user;
            Node* next;
            Node(const User& us) : user(us) , next(nullptr) {}
        };
        std::vector<Node*> table;
        int capacity;
        int size;
        int hashFunction(const std::string& key) const;

    public:
        UserHashTable(int cap = 101);
        bool insert(const User& user);
        void printAllUsers()const;
        User* findByName(const std::string& name);
        ~UserHashTable();
};


#endif