#pragma once
#include "../Product.h"
#include <vector>


class BST{
private:
struct Node{
    std::string name;
    Node * right;
    Node* left;
    std::vector<Product> product;
    };
    Node* root = nullptr;
public:
    ~BST();
    void insert(const std::string& key, const Product& value);
    std::vector<Product>* search(const std::string& key);
    void remove(const std::string& key, int productId);
    Node* removeHelper(Node* current,const std::string& key,int productId);
    void clear(Node* node);


};
