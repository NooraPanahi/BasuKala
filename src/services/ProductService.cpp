#include "../../include/services/ProductService.h"
#include <stdexcept>

PService::PService(): categoryP(5){}

void PService::addProduct(const std::string &name, double price, int category)
{
    auto result = ProductId.emplace(nextId,std::make_unique<Product>(nextId, category, name, price));
    Product* product = result.first->second.get();

    categoryP[category].insert(name, product);
    bestSellerHeap.insert(product);
    trie.insert(name);
    nextId++;
}

void PService::increaseSoldCount(int productId)
{
    Product* p = ProductId.at(productId).get();
    p->increaseSoldCount();

    bestSellerHeap.increaseKey(p);
}

void PService::removeProduct(int productId)
{
    auto it = ProductId.find(productId);
    if (it == ProductId.end())
        throw std::runtime_error("Product not found");

    Product* p = it->second.get();

    int cat = p->getCategory();
    if(cat < 0 || cat >= categoryP.size())
        throw std::runtime_error("Invalid category index");

    std::string name = p->getName();

    categoryP[cat].remove(name, productId, p);

    bestSellerHeap.remove(p);

    ProductId.erase(it);
}
ProductMaxHeap& PService::getBestSellerHeap(){
    return bestSellerHeap;
}

std::vector<BST>& PService::getCategoryP(){
    return categoryP;
}


std::vector<Product*> PService::getAllProductsByName(const std::string& name)
{
    std::vector<Product*> results;

    for(auto& bst : categoryP)
    {
        auto vec = bst.search(name);
        if(vec)
            results.insert(results.end(), vec->begin(), vec->end());
    }

    return results;
}

Product *PService::getProductById(int id){
    auto it = ProductId.find(id);
    if(it != ProductId.end())
        return it->second.get();
    return nullptr;
}
Product* PService::getProductByName(const std::string& name)
{
    for(auto& bst : categoryP)
    {
        auto vec = bst.search(name);
        if(vec && !vec->empty())
            return vec->at(0);   
    }

    return nullptr;
}
Trie& PService::getTrie(){
    return trie;
}