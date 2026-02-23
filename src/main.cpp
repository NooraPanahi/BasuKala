#include <iostream>
#include <vector>
#include "../include/data_structures/Trie/Trie.h"

int main(){

    Trie trie;

    trie.insert("apple", 1);
    trie.insert("apricot", 2);
    trie.insert("application", 3);
    trie.insert("banana", 4);

    int productId;
    if (trie.searchExact("apple", productId)){
        std::cout << "Exact match found. ID = " << productId << "\n";
    }else
        std::cout << "Exact match NOT found.\n";

    std::vector<int> results = trie.searchByPrefix("app");

    std::cout << "\nProducts with prefix 'app':\n";

    for (int id : results)
        std::cout << "ID: " << id << "\n";
}