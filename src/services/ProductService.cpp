#include "../../include/services/ProductService.h"
#include <stdexcept>

PService::PService(): categoryP(5){}

void PService::addProduct(const std::string &name, double price, int category)
{
    auto result = ProductId.emplace(nextId,std::make_unique<Product>(nextId, category, name, price));
    Product* product = result.first->second.get();

    categoryP[category].insert(name, product);
    bestSellerHeap.insert(product);
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
    std::string name = p->getName();

    categoryP[cat].remove(name, productId);

    bestSellerHeap.remove(p);

    ProductId.erase(it);
}
ProductMaxHeap& PService::getBestSellerHeap(){
    return bestSellerHeap;
}

std::vector<BST>& PService::getCategoryP(){
    return categoryP;
}

Product *PService::getProductByName(const std::string& name){
    for(auto& [id, prodPtr] : ProductId){
        if(prodPtr->getName() == name)
            return prodPtr.get();
    }
    return nullptr;
}
