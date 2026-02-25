#pragma once
#include "../Product.h"
#include <vector>
#include <iostream>

class BST{
private:
    struct Node{
        std::string name;
        Node* right;
        Node* left;
        std::vector<Product*> product;   
    };

    Node* root = nullptr;
    void printNode(Node* node)const;
    
public:
    ~BST();
    Node* getNode();
    void printProducts()const;
    void insert(const std::string& key, Product* value);
    std::vector<Product*>* search(const std::string& key);
    void remove(const std::string& key, int productId);

private:
    Node* removeHelper(Node* current, const std::string& key, int productId);
    void clear(Node* node);
};