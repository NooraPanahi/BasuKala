#include "../include/PurchaseService.h"
#include <iostream>
using namespace std;

bool FirstPage(PurchaseService& Pservice){
    
    Pservice.registerUser(Role::normal,"noora",120); //normal user - testing login
    while (true){
        cout << " 0-sign up\n 1-login\n 2-exit\n";
        cout << "enter: ";
        int choose; cin >> choose;

        if(choose == 0){ //sign up
            cout << "enter your name: ";
            string name; cin >> name;
            if(Pservice.userExists(name)){
                cout << "we have this user!! sign in failed\n";
            }else{
                if(Pservice.registerUser(Role::normal,name,200)){// id & balance ?? 
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
            if(Pservice.userExists(name)){
                Pservice.login(name);
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
bool secondPageNormal(PurchaseService& Pservice){
    
    cout << "------------------------------\n";
    cout << Pservice.getCurrentUser()->getName() << '\n';
    cout << "score: " << Pservice.getCurrentUser()->getScore() << '\n';
    cout << "balance: $" << Pservice.getCurrentUser()->getBalance() << '\n';
    cout << "------------------------------\n";

    while(true){
        cout << " 0)store\n 1) increase balance\n 2) purchase history\n 3) log out\n";
        cout << "top selling product:\n";
        //show top selling product

        cout << "enter: ";
        int choose;cin >> choose;
        if(choose == 0){
            //next page for storing
        }
        else if(choose == 1){
            cout << "enter the amount: ";
            int amount ; cin >> amount;
            Pservice.getCurrentUser()->increaseBalance(amount);
            cout << "increased balance successfully\n";
            return true;
        }
        else if(choose == 2){
            cout << "your purchase history:\n";
            Pservice.showPurchaseHistory();
            return true;
        }
        else if(choose == 3){
            cout << "logging out\n";
            Pservice.logout();
            return false;
        }
        else{
            cout << "invalid action.try again\n";
        }

    }


}
int main(){
    PurchaseService Pservice;
    cout << "***Welcome to our shop***\n";
    if(FirstPage(Pservice)){
        if(Pservice.getUsersRole() == Role::admin){

        } 
        if(Pservice.getUsersRole() == Role::normal){
            if(secondPageNormal(Pservice))
                cout << "done\n";
        }        
    }


}