#include "../include/BasuKala.h"
#include "BasuKala.h"
#include <limits>
using namespace std;

BasuKala::BasuKala(): graph(),
      delivery(graph){
    Purchase.registerUser(Role::normal,"noora",120); //normal user - testing login
    pservice.addProduct("vegtables",20,1);
    pservice.addProduct("banana", 80,3);
    pservice.addProduct("tomatoes",10,2);
    pservice.addProduct("baaa",8,4);
    trie.insert("banana"); // testing for searching products
    trie.insert("baaa");
    trie.insert("vegtables");
    trie.insert("tomatoes");
    pservice.increaseSoldCount(1); //to see vegtables in top selling product
  
}
bool BasuKala::signUp(){
    cout << "enter your name: ";
    string name; cin >> name;
    if(Purchase.userExists(name))
        cout << "we have this user!! sign in failed\n";
    else{
        if(Purchase.registerUser(Role::normal,name,200)){// balance ?? 
            Purchase.login(name);
            cout << "signed in successfully!!\n";
            return true;
        }else
            cout << "signed in failed\n";
    }
    return false;
}
bool BasuKala::login(){
    cout << "enter your name: ";
    string name; cin >> name;
    if(Purchase.userExists(name)){
        Purchase.login(name);
        cout << "logged in successfully\n";
        // to check basket
            Product p(3,4,"banana",30);
            Purchase.addToBasket(p);
            Product pp(5,3,"rrr",43);
            Purchase.addToBasket(pp);
        //
        return true;
    }else
        cout << "no user found\n";

    return false;    
}
void BasuKala::increaseBalance(){
    cout << "enter the amount: ";
    int amount ; cin >> amount;
    Purchase.getCurrentUser()->increaseBalance(amount);
    cout << "increased balance successfully\n";

}
bool BasuKala::showCategories(){
    std::vector<BST>& products = pservice.getCategoryP();
    cout << "categories: \n";
    for(size_t i = 0 ; i < products.size(); i++)
    cout << i << ") Category " << i << '\n';

    cout << "enter category number to view products: ";
    int catId; cin >> catId;

    if(catId < 0 || catId >= static_cast<int>(products.size())){
        cout << "invalid category number\n";
        return false;
    }
    BST* bst = &products[catId];
    auto root = bst->getNode();
    if(!bst->getNode())
        cout << "no products in this category\n";
    else{
        bst->printProducts(true);
        ChooseItem();  
    }
    return true;
}
void BasuKala::search(){
    cout << "enter the name of product: ";
    string pro; cin >> pro;
    vector<std::string> res = trie.searchByPrefix(pro);
    if(res.empty())
        cout << "no product found\n";
    else{
        cout << "search results:\n";
        for(size_t i = 0 ; i < res.size(); i++){
            std::string proName = res[i];
            Product* p = pservice.getProductByName(proName);
            if(p)
                cout << "id: " << p->getId() << ") " << p->getName() << ", $" << p->getPrice() << '\n';  
        }
        ChooseItem();
    }
}
void BasuKala::editCart(){
    if(Purchase.CheckIfBasketExists()){
        cout << "products in your basket: \n";
        const std::vector<Product> & items = Purchase.getCurrentBasket().getProducts();
        for(int i = 0 ; i < static_cast<int>(items.size()); i++)
            std::cout << "Id: "<< items[i].getId() << ") " << items[i].getName() << " | $" << items[i].getPrice() << '\n';
        
        std::cout << "Total cost: " << Purchase.getCurrentBasket().getTotalPrice() << '\n'
                    << "balance: " << Purchase.getCurrentUser()->getBalance() << '\n';
        cout << "enter the product's id to remove: ";
        int remove; cin >> remove;
        if(Purchase.removeFromBasket(remove))
            cout << "Item removed successfully\n";
        else 
            cout << "uncorrect id\n";
    }
}
bool BasuKala::firstPage(){

    while (true){
        cout << " 0-sign up\n 1-login\n 2-exit\n";
        cout << "enter: ";
        int choose; cin >> choose;

        if(choose == 0){ //sign up
            if(signUp())
                return true;
        }
        else if(choose == 1){ //login
            if(login())
                return true;

        }
        else if(choose == 2){ //exit
            cout << "goodbye!!\n";
            return false;
        }
        else
            cout << "invalid action.try again\n";
    }
}
bool BasuKala::secondPageNormal(){
    cout << "------------------------------\n";
    cout << Purchase.getCurrentUser()->getName() << '\n';
    cout << "score: " << Purchase.getCurrentUser()->getScore() << '\n';
    cout << "balance: $" << Purchase.getCurrentUser()->getBalance() << '\n';
    cout << "------------------------------\n";

    while(true){
        cout << " 0)store\n 1) increase balance\n 2) purchase history\n 3) log out\n";
        cout << "**top selling product:\n";
        Product* topProduct = pservice.getBestSellerHeap().top();
        if(topProduct)
            cout << topProduct->getName() << '\n';
        else cout << "No top selling product yet\n";

        cout << "enter: ";
        int choose;cin >> choose;
        if(choose == 0){
            return true;
        }
        else if(choose == 1){
            increaseBalance();
        }
        else if(choose == 2){
            cout << "your purchase history:\n";
            Purchase.showPurchaseHistory();
        }
        else if(choose == 3){
            cout << "logging out\n";
            Purchase.logout();
            return false;
        }
        else
            cout << "invalid action.try again\n";
    }
}
bool BasuKala::storePageNormal(){
    while (true){
        cout << "----------\n";
        cout << "-2)removed products\n-1) back\n 0) categories\n 1) search by name\n 2) edit cart\n 3) complete purchase\n";
        cout << "enter: ";
        int choose; cin >> choose;
        if(choose == -1)
            return false;
        else if(choose == 0){ // show categories
           if(!showCategories())
                continue;
        }
        else if(choose == 1) //search
            search();
        else if(choose == 2) //edit cart
            editCart();
        else if(choose == -2){ // add the last removed item
            if(Purchase.getCurrentBasket().undoLastRemovedItem())
                cout << "last removed item restored successsfully\n";
            else  
                cout << "no removed item to restore\n";

        }
        else if(choose == 3){ //complete purchase
            completePurchase();
        }
        else
            cout << "invalid action.try again\n"; 
    }  
}
void BasuKala::completePurchase()
{
    cout << "\nEnter your city id from this list:\n";

    const vector<City>& cities = graph.getCitiesList();

    for(const auto& c : cities){
        cout << "Id: " << c.getId()
             << "\tName: " << c.getName() << '\n';
    }

    int id;

    while(true){
        cout << "Enter city id: ";

        if(!(cin >> id)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        bool found = false;
        for(const auto& c : cities){
            if(c.getId() == id){
                found = true;
                break;
            }
        }

        if(!found){
            cout << "City id not found. Try again.\n";
            continue;
        }

        break;
    }

    try{
        Order order = Purchase.checkout(id);
        delivery.addOrder(order);
        cout << "Order registered successfully.\n";
    }
    catch(const std::exception& e){
        cout << e.what() << '\n';
    }
}
void BasuKala::ChooseItem(){
    cout << "enter product id to add (-1 to cancel): ";
    int id; cin >> id;
    if(id != -1){
        Product* p = pservice.getProductById(id);
        if(p){
            Purchase.addToBasket(*p);
            cout << "added to basket successfully\n";
        }
        else 
            cout << "invalid product id\n";
    }
}

void BasuKala::run(){
    cout << "***Welcome to our shop***\n";
    if(firstPage()){
        if(Purchase.getUsersRole() == Role::admin){

        } 
        if(Purchase.getUsersRole() == Role::normal){
            while (true){
                if(secondPageNormal())
                    if(storePageNormal()){}
            }             
        }        
    }
}