#ifndef USER_H
#define USER_H
#include "PurchaseHistory.h"

enum Role{ normal , admin };

class User{
    private:
        Role role;
        std::string name;
        double balance;
        int score;
        std::vector<int> orderIds;
        PurchaseHistory history;
        int id;
    public:
        User(Role role,const std::string& name , double balance, int score, int id):role(role), name(name) , balance(balance) , score(score), id(id){};
        std::string getName()const{
            return name;
        }
        int getId() const {
            return id;
        }
        
        Role getRole()const{
            return role;
        }
        double getBalance()const{
            return balance;
        }
        int getScore()const{
            return score;
        }
        void increaseBalance(double amount){
            balance += amount;
        }
        void decreaseBalance(double amount){
            balance -= amount;
        }

        bool hasEnoughBalance(int amount)const{
            return balance >= amount;
        } 
        void increaseScore(int amount){
            score+= amount;
        }
        PurchaseHistory& getHistory(){
            return history;
        }
};

#endif