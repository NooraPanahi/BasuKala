#include "PurchaseHistory.h"

PurchaseHistory::PurchaseHistory(): head(nullptr), tail(nullptr){}

PurchaseHistory::~PurchaseHistory(){
    Node* current = head;

    while(current){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void PurchaseHistory::addOrder(const Order &order){
    Node* newnode = new Node(order);

    if(!head){
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void PurchaseHistory::display() const{
    if(!head){
        std::cout << "No purchase history.\n";
        return;
    }
    Node* current = head;
    std::cout << "your purchase history:\n";
    while(current){
        const Order& o = current->order;
        std::cout << "Order ID: " << o.getOrderId() << '\n';
        std::cout << "Total Price: " << o.getTotalPrice() << '\n';
        std::cout << "Timestamp: " << o.getTimeStamp() << '\n';
        std::cout << "----------------------------------\n";

        current = current->next;
    }
}

bool PurchaseHistory::isEmpty() const{
    return (head == nullptr);
}
