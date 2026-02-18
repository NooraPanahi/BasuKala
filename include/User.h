#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

class User{
    private:
        int id;
        std::string name;
        double balance;
        int score;
        std::vector<int> orderIds;
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
        bool hasEnoughBalance()const{
            return balance > 0;
        } 
        void increaseScore(int amount){
            score+= amount;
        }
};

#endif