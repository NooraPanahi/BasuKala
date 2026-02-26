#include "../include/PurchaseService.h"

PurchaseService::PurchaseService() : currentUser(nullptr), nextOrderId(1) {}

bool PurchaseService::registerUser(Role role,
                                   const std::string& name,
                                   double balance)
{
User newUser(role, name, balance, 0, nextUserId);

if(!users.insert(newUser))
    return false;

User* insertedUser = users.findByName(name);

usersById.emplace(nextUserId, insertedUser);
nextUserId++;
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
User* PurchaseService::user_getter(int id) const
{
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

Order PurchaseService::checkout(int cityId)
{
    if(!currentUser)
        throw std::runtime_error("No user logged in");

    if(currentBasket.isEmpty())
        throw std::runtime_error("Basket is empty");

    double total = currentBasket.getTotalPrice();

    if(!currentUser->hasEnoughBalance(total))
        throw std::runtime_error("Not enough balance");

    currentUser->decreaseBalance(total);

    std::vector<int> productIds;
    for(const auto& item : currentBasket.getProducts())
        productIds.push_back(item.getId());

    long long ts = nextTimestamp++;
    int frozenScore = currentUser->getScore();

    Order order(
        nextOrderId++,
        productIds,
        total,
        frozenScore,
        cityId,
        ts,
        currentUser->getId()
    );

    currentUser->getHistory().addOrder(order);
    currentBasket.clear();

    return order;
}

void PurchaseService::showAllUsers() const{
    users.printAllUsers();
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
