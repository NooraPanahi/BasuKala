#pragma once
#include "../Product.h"
#include <vector>
#include <iostream>

class BST{
private:
    struct Node{
        std::string name;
        double price;
        Node* right;
        Node* left;
        std::vector<Product*> productbyname;   
        std::vector<Product*> productbyprice;   


    };
    Node* root2 = nullptr;
    Node* root = nullptr;
    void printNode(Node* node)const;
        Node* removeHelper(Node* current, const std::string& key, int productId);
    void clear(Node* node);
public:
    ~BST();
    void printbyprice(Node* node) const;
    Node* getNode();
    void printProducts(bool nameOrprice)const; //true = name     false = price
    void insert(const std::string& key, Product* value);

    void insertbyname(const std::string& key, Product* value);
        void insertbyprice(const std::string& key, Product* value);

    std::vector<Product*>* search(const std::string& key);
    void remove(const std::string& key, int productId, Product* value);
BST::Node* removeHelperprice(Node* current,
                             Product* value,
                             int productId);

};