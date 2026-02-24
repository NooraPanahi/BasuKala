#include "ProductService.h"
#include <stdexcept>
void PService::addProduct(const std::string &name, double price, int category)
{
    ProductId.emplace(nextId,Product(nextId, category, name, price));
    Product* product = &ProductId[nextId];
    categoryP[category].insert(name, product);
    bestSellerHeap.insert(product);
    nextId++;
}

void PService::increaseSoldCount(int productId)
{
    Product* p = &ProductId.at(productId);
    p->increaseSoldCount();

    bestSellerHeap.increaseKey(p);
}

void PService::removeProduct(int productId)
{
    auto it = ProductId.find(productId);
    if (it == ProductId.end())
        throw std::runtime_error("Product not found");

    Product* p = &it->second;

    int cat = p->getCategory();
    std::string name = p->getName();

    categoryP[cat].remove(name, productId);

    bestSellerHeap.remove(p);

    ProductId.erase(it);
}
ProductMaxHeap PService::getBestSellerHeap(){
    return bestSellerHeap;
}
