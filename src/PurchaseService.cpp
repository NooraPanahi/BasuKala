#include "../include/PurchaseService.h"

PurchaseService::PurchaseService() : currentUser(nullptr), nextOrderId(1) {}

bool PurchaseService::registerUser(Role role,
                                   const std::string &name,
                                   double balance)
{
    int id = nextUserId++;
    
    User newUser(role, name, balance, 0, id);

    if(!users.insert(newUser))
        return false;

    User* insertedUser = users.findByName(name);

    usersById.emplace(id, insertedUser);

    return true;
}

bool PurchaseService::login(const std::string &name){
    currentUser = users.findByName(name);
    return currentUser != nullptr;
}

void PurchaseService::logout(){
    currentUser = nullptr;
    currentBasket.clear();
}
User* PurchaseService::user_getter(int id) const{
    auto it = usersById.find(id);
    if(it == usersById.end())
        return nullptr;
    return it->second;
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

bool PurchaseService::CheckIfBasketExists() const{
    if(currentBasket.isEmpty()){
        std::cout << "Basket is empty.\n";
        return false;
    }
    return true;
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
    
    Order order(nextOrderId++, productIds,total,0,cityId,timestamp, currentUser->getId());
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

Basket& PurchaseService::getCurrentBasket(){
    return currentBasket;
}
