#ifndef USER_H
#define USER_H
#include "PurchaseHistory.h"
class User{
    private:
        int id;
        std::string name;
        double balance;
        int score;
        std::vector<int> orderIds;
        PurchaseHistory history;
    public:
        User(int id,const std::string& name , double balance, int score): id(id) , name(name) , balance(balance) , score(score){};
        int getId()const{
            return id;
        }
        std::string getName()const{
            return name;
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
