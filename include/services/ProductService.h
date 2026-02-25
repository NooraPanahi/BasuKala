#pragma once
#include "../data_structures/max_heap.h"
#include "../data_structures/BST.h"
#include <unordered_map>
#include <memory>
class PService{
private:
    std::vector <BST> categoryP;
    ProductMaxHeap bestSellerHeap;
    std::unordered_map <int,std::unique_ptr<Product>> ProductId;
    int nextId = 1;
public:
    PService();
    void addProduct(const std::string& name, double price, int category);
    void increaseSoldCount(int productId);
    void removeProduct(int productId);
    ProductMaxHeap& getBestSellerHeap();
    std::vector<BST>& getCategoryP();
std::vector<Product*> getAllProductsByName(const std::string& name);
    Product* getProductById(int id);
    Product* getProductByName(const std::string& name);
};