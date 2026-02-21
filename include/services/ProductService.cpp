#include "ProductService.h"

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
    Product* p = &ProductId[productId];

    p->increaseSoldCount();

    bestSellerHeap.increaseKey(p);
}

void PService::removeProduct(int productId)
{
    Product* p = &ProductId[productId];


}
