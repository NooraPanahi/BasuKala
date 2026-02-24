#include "../include/data_structures/Hash/UserHashTable.h"

UserHashTable::UserHashTable(int cap): capacity(cap),size(0), table(cap , nullptr){}

int UserHashTable::hashFunction(const std::string &key) const{
    unsigned long hash = 0 ;
    for(char c : key)
        hash = hash * 31 + c;

    return hash % capacity;
}

bool UserHashTable::insert(const User& user){

    int index = hashFunction(user.getName());
    Node* current = table[index];

    while(current){
        if(current->user.getName() == user.getName())
            return false;
        current = current->next ;
    }
    Node* newNode = new Node(user);
    newNode->next = table[index];
    table[index] = newNode;

    size++; 
    return true;
}

User* UserHashTable::findByName(const std::string& name){
    int index = hashFunction(name);
    Node* current = table[index];

    while(current){
        if(current->user.getName() == name)
            return &(current->user);
        current = current->next;
    }
    return nullptr;
}

UserHashTable::~UserHashTable(){
    for(int i = 0 ; i < capacity; i++){
        Node* current = table[i];
        while (current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        
    }
}