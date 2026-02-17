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
        User(int id,const std::string& name , double balance, int score);
        int getId()const;
        std::string getName()const;
        double getBalance()const;
        int getScore()const;

        void increaseBalance(double amount);
        void decreaseBalance(double amount);
        bool checkBalance()const; //using in decreaseBalance
        void increaseScore(int amount);
};

#endif
