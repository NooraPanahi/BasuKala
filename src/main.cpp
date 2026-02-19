#include "../include/PurchaseHistory.h"
#include <vector>
int main(){
    PurchaseHistory history;
    std::vector<int> products = {1,2,3};
    Order o1(1,1,products,150.0,0,1,123456);
    Order o2(2,1,products,200.0,0,1,123446);
    history.addOrder(o1);
    history.addOrder(o2);

    history.display();
}