#include "../include/data_structures/Trie/Trie.h"

Trie::Node::Node(): endOfTheWord(false), productId(-1){
    for(int i = 0 ; i < 26; i++)
        children[i] = nullptr;
}
Trie::Trie(){
    root = new Node();
}
Trie::~Trie(){
    deleteNode(root);
}

void Trie::deleteNode(Node *node)
{
    if(!node) return;

    for (int i = 0; i < 26; i++)
        deleteNode(node->children[i]);
    delete node;
}
void Trie::insert(const std::string &word, int productId){
    Node* current = root;
    for(char c : word){
        if(c < 'a' || c > 'z')
            continue;
        
        int index = c - 'a';
        if(!current->children[index])
            current->children[index] = new Node();

        current = current->children[index];
    }
    current->endOfTheWord = true;
    current->productId = productId;
}

bool Trie::searchExact(const std::string &word, int &productId) const{
    Node* current = root;
    for(char c : word){
        if(c < 'a' || c > 'z') 
            return false;

        int index = c - 'a';

        if(!current->children[index]) 
            return false;

        current = current->children[index];
    }
    if(current->endOfTheWord){
        productId = current->productId;
        return true;
    }
    return false;
}

std::vector<int> Trie::searchByPrefix(const std::string &prefix) const{
    std::vector<int>results;
    Node* current = root;

    for(char c : prefix){
        if(c < 'a' || c > 'z')
            return results;

        int index = c - 'a';

        if(!current->children[index]) 
            return results;
        
        current = current->children[index];
    }
    collectAllWords(current, results);
    return results;
}
void Trie::collectAllWords(Node *node, std::vector<int> &results) const{
    if(!node) return;
    if(node->endOfTheWord)
        results.push_back(node->productId);

    for(int i = 0 ; i < 26 ; i ++)
        collectAllWords(node->children[i], results);
}