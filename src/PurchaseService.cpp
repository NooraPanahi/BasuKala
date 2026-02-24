#include "../include/PurchaseService.h"
#include "PurchaseService.h"

PurchaseService::PurchaseService() : currentUser(nullptr), nextOrderId(1) {}

bool PurchaseService::registerUser(Role role, const std::string &name, double balance){
    return users.insert(User(role,name,balance,0));
}

bool PurchaseService::login(const std::string &name){
    currentUser = users.findByName(name);
    return currentUser != nullptr;
}

void PurchaseService::logout(){
    currentUser = nullptr;
    currentBasket.clear();
}

void PurchaseService::addToBasket(const Product& product){
    if(!currentUser) return;
    currentBasket.addProduct(product);
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
    const std::vector<Product> & items = currentBasket.getProducts();
    for(int i = 0 ; i < static_cast<int>(items.size()); i++)
        std::cout << i << ") " << " Product ID: " << items[i].getId() << ", Price: " << items[i].getPrice() << '\n';
    
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
        productIds.push_back(item.getId());
    
    Order order(nextOrderId++, productIds,total,0,cityId,timestamp);
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

bool PurchaseService::userExists(const std::string &name){
    return users.findByName(name) != nullptr;
}

Role PurchaseService::getUsersRole() const{
    return currentUser->getRole();
}

User *PurchaseService::getCurrentUser() const{
    return currentUser;
}
