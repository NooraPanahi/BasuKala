#ifndef TRIE_H
#define TRIE_H
#include<vector>
#include <string>
class Trie{
    private:
        struct Node
        {
            Node* children[26];
            bool endOfTheWord;
            int productId;
            Node();
        };
        Node* root;
        void collectAllWords(Node* node, std::vector<int>& results)const;
        void deleteNode(Node* node);
    public:
        Trie();
        ~Trie();
        void insert(const std::string& word, int productId);
        bool searchExact(const std::string& word, int& productId)const;
        std::vector<int> searchByPrefix(const std::string& prefix) const;
};


#endif