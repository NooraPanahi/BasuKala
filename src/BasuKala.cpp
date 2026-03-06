#include "../include/BasuKala.h"
#include <limits>
using namespace std;

BasuKala::BasuKala(): graph(),
      delivery(graph){
    Purchase.registerUser(Role::normal,"noora",120); //normal user
    Purchase.registerUser(Role::admin, "mina", 0); // admin
    Purchase.registerUser(Role::normal, "zahra", 0);
    Purchase.registerUser(Role::normal, "narges", 0);

    pservice.addProduct("vegtables",20,1);
    pservice.addProduct("apple",20, 0);
    pservice.addProduct("banana", 80,3);
    pservice.addProduct("tomatoes",10,2);
    pservice.addProduct("avocado", 100, 1);
    pservice.addProduct("blueberry", 35, 4);

    graph.addCity("Bimsy", false);
    graph.addCity("Garoua", true);
    graph.addCity("Debrecen", false);
    graph.addCity("Lae", false);
    graph.addCity("Merribell", false);
    graph.addCity("Wimble", false);
    graph.addCity("Aguascalientes", false);
    graph.addCity("Froli", false);
    graph.addCity("Tainan", true);
    graph.addCity("Honiara", false);
    graph.addCity("Twinklehollow", false);
    graph.addCity("Trinkleby", false);
        // A - B (2)
    graph.addedge(2, 1, 0);

    // A - C (5)
    graph.addedge(5, 2, 0);

    // B - F (5)
    graph.addedge(5, 5, 1);

    // D - E (1)
    graph.addedge(1, 4, 3);

    // E - C (4)
    graph.addedge(4, 2, 4);

    // E - F (2)
    graph.addedge(2, 5, 4);

    // E - G (3)
    graph.addedge(3, 6, 4);

    // F - G (5)
    graph.addedge(5, 6, 5);

    // F - H (3)
    graph.addedge(3, 7, 5);

    // H - G (4)
    graph.addedge(4, 6, 7);

    // G - I (2)
    graph.addedge(2, 8, 6);

    // G - J (4)
    graph.addedge(4, 9, 6);

    // C - L (3)
    graph.addedge(3, 11, 2);

    // C - K (4)
    graph.addedge(4, 10, 2);

    // C - J (6)
    graph.addedge(6, 9, 2);

    // G - K (10)
    graph.addedge(10, 10, 6);

    // K - J (8)
    graph.addedge(8, 9, 10);
   // pservice.increaseSoldCount(2); //to see vegtables in top selling product
  
}
bool BasuKala::signUp(){
    cout << "enter your name: ";
    string name; cin >> name;
    if(Purchase.userExists(name))
        cout << "we have this user!! sign in failed\n";
    else{
        if(Purchase.registerUser(Role::normal,name,0)){ // By default balance = 0
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
        return true;
    }else
        cout << "no user found\n";

    return false;    
}
void BasuKala::increaseBalance(){
    cout << "enter the amount: ";
    int amount ; cin >> amount;
    if(amount <= 0){
        cout << "amount must be positive.\n";
        return;
    }
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

    if(!bst->getNode())
        cout << "no products in this category\n";

    bool nameFirst = true;

    while (true){
        cout << "-1) back\n-2) Swap product name and price display order\n";
        bst->printProducts(nameFirst);
        cout << "enter product id to add: ";
        int id; cin >> id;
        if(id == -1)
            return false;
        else if(id == -2){
            nameFirst = !nameFirst;
            cout << ">>Display order swapped!\n";
            continue;
        }
        else{
            Product* p = pservice.getProductById(id);
            if(!p) 
                cout << "invalid product id\n";
            else if(p->getCategory() != catId) 
                cout << "this product does not belong to this category\n";
            else{
                Purchase.addToBasket(*p);
                cout << "added to basket successfully\n";
            }
        }
    }
    return true;
}
void BasuKala::search(){
    cout << "enter the name of product: ";
    string pro; cin >> pro;
    vector<string> res = pservice.getTrie().searchByPrefix(pro);
    if(res.empty()){
        cout << "no product found\n";
        return;
    }
    cout << "search results:\n";
    vector<Product*> allowed;
    for(const auto& name : res){
        Product* p = pservice.getProductByName(name);
        if(p)
            allowed.push_back(p);             
    }
    Product* choosen = ChooseItem(allowed);
    if(choosen){
        Purchase.addToBasket(*choosen);
        cout << "added to basket successfully\n";
    }
    
}
void BasuKala::editCart(){
    if(Purchase.CheckIfBasketExists()){
        cout << "products in your basket: \n";
        const std::vector<Product> & items = Purchase.getCurrentBasket().getProducts();
        for(int i = 0 ; i < static_cast<int>(items.size()); i++)
            std::cout << "Id: "<< items[i].getId() << ") " << items[i].getName() << " | $" << items[i].getPrice() << '\n';
        
        std::cout << "Total cost: $" << Purchase.getCurrentBasket().getTotalPrice() << '\n'
                    << "balance: $" << Purchase.getCurrentUser()->getBalance() << '\n';
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
        Product * top = nullptr;
        if(!pservice.getBestSellerHeap().empty())
            top = pservice.getBestSellerHeap().top();
        if(top && top->getSoldCount() > 0)
            cout << top->getName() << '\n';
        else cout << "No top selling product yet\n";

        cout << "enter: ";
        int choose;cin >> choose;

        switch (choose){
        case 0:
            return true;
        case 1:
            increaseBalance();
            break;
        case 2:
            Purchase.showPurchaseHistory(pservice);
            break;
        case 3:
            Logout();
            return false; 
        default:
            cout << "invalid action.try again\n";
            break;
        }
    }
}
void BasuKala::undolastremoveditem(){
    if(Purchase.getCurrentBasket().undoLastRemovedItem())
        cout << "last removed item restored successsfully\n";
    else  
        cout << "no removed item to restore\n";
}
bool BasuKala::storePageNormal(){
    while (true){
        cout << "----------\n";
        cout << "-2)removed products\n-1) back\n 0) categories\n 1) search by name\n 2) edit cart\n 3) complete purchase\n";
        cout << "enter: ";
        int choose; cin >> choose;
        switch (choose){
            case -1:
                Purchase.getCurrentBasket().clear(); 
                return false;
            case 0:
                if(!showCategories())
                    continue;
                break;
            case 1:
                search();
                break;
            case 2:
                editCart();
                break;
            case -2: 
                undolastremoveditem();
                break;
            case 3:
                completePurchase();
                break;
            default:
                cout << "invalid action. try again\n";
                break;
        }
    }  
}
void BasuKala::completePurchase(){

    if(!Purchase.CheckIfBasketExists()){
        return;
    }
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
        Order order = Purchase.checkout(id, pservice);
        delivery.addOrder(order);
        cout << "Order registered successfully.\n";
    }
    catch(const std::exception& e){
        cout << e.what() << '\n';
    }
}
Product* BasuKala::ChooseItem(const std::vector<Product*>& allowedProducts){
    if(allowedProducts.empty()){
        cout << "no items available.\n";
        return nullptr;
    }
    cout << "-1) cancel\n";
    for(size_t i = 0 ; i < allowedProducts.size(); i++)
        cout << i << ") " << allowedProducts[i]->getName() << "| $" << allowedProducts[i]->getPrice() << '\n';
    
    cout << "enter choice: ";
    int choice; cin >> choice;
    if(choice == -1)
        return nullptr;
    if(choice < 0 || choice >= static_cast<int> (allowedProducts.size())){
        cout << "invalid choice\n";
        return nullptr;
    }
    return allowedProducts[choice];
}
void BasuKala::Logout(){
    Purchase.logout();
    cout << "logged out successfully\n";
}
void BasuKala::addProductAdmin(){
    string name; double price; int category;
    cout << "enter name: "; cin >> name;
    cout << "enter price: "; cin >> price;
    cout << "enter category(0-4): "; cin >> category;

    if(category < 0 || category >= 5){
        cout << "invalid category\n";
        return;
    }
    pservice.addProduct(name,price,category);
    cout << "Product added successfully\n";
}
void BasuKala::removeProductAdmin(){
    std::vector<BST>& cate = pservice.getCategoryP();
    cout << "categories:\n";
    for(size_t i = 0 ; i <cate.size(); i++)
        cout << i << ") category " << i << '\n';
    cout << "enter category: ";
    int cat; cin >> cat;
    if(cat < 0 || cat >= static_cast<int>(cate.size())){
        cout << "invalid category\n";
        return;
    } 
    BST & bst = cate[cat];
    if(!bst.getNode()){
        cout << "no product in this category\n";
        return;
    }
    bst.printProducts(true);
    cout << "enter product id to remove: ";
    int id; cin >> id;
    Product *p = pservice.getProductById(id);
    if(!p){
        cout << "product not found\n";
        return;
    }
    if(p->getCategory() != cat){
        cout << "This product does not belong to this category\n";
        return;
    }
    try{
        pservice.removeProduct(id);
        cout << "product removed successfully\n";
    }
    catch(exception& e){
        cout << e.what() << '\n';
    }
}

void BasuKala::deliverOrders(){
    if(!delivery.hasOrders()){
        cout << "No orders in delivery queue.\n";
        return;
    }
    while (delivery.hasOrders()){
        try{
            delivery.dispatchNext(Purchase);
        }
        catch( exception& e){
            cout << e.what() << '\n';
            break;
        } 
    }
    cout << "all orders processed\n"; 
}
void BasuKala::normalMenu(){
    while (true){
        bool goToStore = secondPageNormal();
        if(!goToStore)
            break;
        storePageNormal();
    }
}

void BasuKala::adminMenu(){
    while (true){
        cout << "---admin panel---\n";
        cout << " 0)Add product\n 1)Remove product\n 2)Veiw users info\n 3)Deliver orders\n 4)Logout\n";
        cout << "enter: ";
        int choose; cin >> choose;
        switch (choose){
        case 0:
            addProductAdmin();
            break;
        case 1:
            removeProductAdmin();
            break;
        case 2:
            Purchase.showAllUsers();
            break;
        case 3:
            deliverOrders();
            break;
        case 4:
            Logout();
            return;
        default:
            cout << "invalid action.try again\n";
            break;
        }
    }
}
void BasuKala::run(){
    cout << "***Welcome to our shop***\n";
    while (true){
        if(!firstPage())
            break;
        Role role = Purchase.getUsersRole();
        if(role == Role::admin)
            adminMenu();
        else
            normalMenu();
    }
}