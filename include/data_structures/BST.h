#pragma once
#include "../Product.h"
#include <vector>
#include <string>

class BST{
private:
    struct Node{
        std::string name;
        Node* right;
        Node* left;
        std::vector<Product*> product;   
    };

    Node* root = nullptr;

public:
    ~BST();

    void insert(const std::string& key, Product* value);
    std::vector<Product*>* search(const std::string& key);
    void remove(const std::string& key, int productId);

private:
    Node* removeHelper(Node* current, const std::string& key, int productId);
    void clear(Node* node);
};