#include "../include/PurchaseService.h"

PurchaseService::PurchaseService() : currentUser(nullptr), nextOrderId(1) {}

bool PurchaseService::registerUser(int id, const std::string &name, double balance){
    return users.insert(User(id,name,balance,0));
}

bool PurchaseService::login(const std::string &name){
    currentUser = users.findByName(name);
    return currentUser != nullptr;
}

void PurchaseService::logout(){
    currentUser = nullptr;
    currentBasket.clear();
}

void PurchaseService::addToBasket(int productId, double price){
    if(!currentUser) return;
    currentBasket.addProduct(productId,price);
}


bool PurchaseService::removeFromBasket(int index)
{
    if(!currentUser) return false;

    return currentBasket.removeProductByIndex(index);
    
}

void PurchaseService::veiwBasket() const{
    if(!currentUser){
        std::cout << "No user logged in.\n";
        return;
    }
    if(currentBasket.isEmpty()){
        std::cout << "Basket is empty.\n";
        return;
    }
    const std::vector<Item> & items = currentBasket.getProducts();
    for(int i = 0 ; i < static_cast<int>(items.size()); i++)
        std::cout << i << ") " << " Product ID: " << items[i].productId << ", Price: " << items[i].price << '\n';
    
    std::cout << "Total price: " << currentBasket.getTotalPrice() << '\n';

}

bool PurchaseService::checkout(int cityId, long long timestamp){
    if(!currentUser || currentBasket.isEmpty()) return false;

    double total = currentBasket.getTotalPrice();

    if(!currentUser->hasEnoughBalance(total))
        return false;
    
    currentUser->decreaseBalance(total);

    std::vector<int> productIds;
    for(const auto& item : currentBasket.getProducts())
        productIds.push_back(item.productId);
    
    Order order(nextOrderId++, currentUser->getId(), productIds,total,0,cityId,timestamp);
    currentUser->getHistory().addOrder(order);
    currentBasket.clear();
    return true;
    
}

void PurchaseService::showPurchaseHistory() const{
    if(!currentUser){
        std::cout << "No user logged in\n";
        return ;
    }
    currentUser->getHistory().display();
}
