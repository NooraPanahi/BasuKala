#include "../include/BasuKala.h"
using namespace std;

BasuKala::BasuKala(){
    Purchase.registerUser(Role::normal,"noora",120); //normal user - testing login
  
}
bool BasuKala::firstPage(){
    while (true){
        cout << " 0-sign up\n 1-login\n 2-exit\n";
        cout << "enter: ";
        int choose; cin >> choose;

        if(choose == 0){ //sign up
            cout << "enter your name: ";
            string name; cin >> name;
            if(Purchase.userExists(name)){
                cout << "we have this user!! sign in failed\n";
            }else{
                if(Purchase.registerUser(Role::normal,name,200)){// id & balance ?? 
                    cout << "signed in successfully!!\n";
                    return true;
                }else{
                    cout << "signed in failed\n";
                }
            }
        }
        else if(choose == 1){ //login
            cout << "enter your name: ";
            string name; cin >> name;
            if(Purchase.userExists(name)){
                Purchase.login(name);
                cout << "logged in successfully\n";
                return true;
            }else{
                cout << "no user found\n";
            }
        }
        else if(choose == 2){ //exit
            cout << "goodbye!!\n";
            return false;
        }
        else{
            cout << "invalid action.try again\n";
        }
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
        cout << "top selling product:\n";
        cout << pservice.getBestSellerHeap().top()->getName() << '\n';
        //show top selling product

        cout << "enter: ";
        int choose;cin >> choose;
        if(choose == 0){
            //next page for storing
        }
        else if(choose == 1){
            cout << "enter the amount: ";
            int amount ; cin >> amount;
            Purchase.getCurrentUser()->increaseBalance(amount);
            cout << "increased balance successfully\n";
            return true;
        }
        else if(choose == 2){
            cout << "your purchase history:\n";
            Purchase.showPurchaseHistory();
            return true;
        }
        else if(choose == 3){
            cout << "logging out\n";
            Purchase.logout();
            return false;
        }
        else{
            cout << "invalid action.try again\n";
        }

    }


}
void BasuKala::run(){
    cout << "***Welcome to our shop***\n";
    if(firstPage()){
        if(Purchase.getUsersRole() == Role::admin){

        } 
        if(Purchase.getUsersRole() == Role::normal){
           if(secondPageNormal())
                cout << "done\n";
        }        
    }
}