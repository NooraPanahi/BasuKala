#include "../include/data_structures/Stack/ItemStack.h"
#include "ItemStack.h"

ItemStack::ItemStack(): node(nullptr){}

ItemStack::~ItemStack(){
    while (node){
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

void ItemStack::push(const Item &item){
    Node* newNode = new Node(item);
    newNode->next = node;
    node = newNode;
}

bool ItemStack::pop(Item &removedItem){
    if(!node) return false;

    Node* temp = node;
    removedItem = node->data;
    node = node->next;
    delete temp;

    return true;
}

bool ItemStack::isEmpty() const{
    return (node == nullptr);
}
