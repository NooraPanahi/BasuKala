#pragma once
#include "max_heap.h"
#include "BST.h"
#include <unordered_map>
class PService{
private:
    std::vector <BST> categoryP;
    ProductMaxHeap bestSellerHeap;
    std::unordered_map <int, Product> ProductId;
    int nextId = 1;
public:
    void addProduct(const std::string& name, double price, int category);
    void increaseSoldCount(int productId);
    void removeProduct(int productId);
    ProductMaxHeap getBestSellerHeap();

};