#include "../../include/data_structures/BST.h"



void BST::insert(const std::string &key, const Product &value)
{
    if (!root) {
        Node* newnode = new Node;
        newnode->left = newnode->right = nullptr;
        newnode->name = key;
        newnode->product.push_back(value);
        root = newnode;
        return;
    }

    Node* temp = root;
    Node* parent = nullptr;

    while (temp) {
        if (temp->name == key) {
            temp->product.push_back(value);
            return;
        }

        parent = temp;

        if (key < temp->name) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    Node* newnode = new Node;
    newnode->left = newnode->right = nullptr;
    newnode->name = key;
    newnode->product.push_back(value);

    if (key < parent->name) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }
}

std::vector<Product>* BST::search(const std::string& key)
{
    Node* current = root;

    while (current) {
        if (key == current->name) {
            return &(current->product);
        }
        else if (key < current->name) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return nullptr;
}


void BST::remove(const std::string& key, int productId)
{
    root = removeHelper(root, key, productId);
}

BST::Node* BST::removeHelper(Node* current,const std::string& key,int productId)
{
    if (!current)
        return nullptr;

    if (key < current->name) {
        current->left = removeHelper(current->left, key, productId);
    }
    else if (key > current->name) {
        current->right = removeHelper(current->right, key, productId);
    }
    else {
        auto& vec = current->product;
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (it->getId() == productId) {
                vec.erase(it);
                break;
            }
        }

        if (!vec.empty())
            return current;


        if (!current->left && !current->right) {
            delete current;
            return nullptr;
        }

     
        if (!current->left) {
            Node* temp = current->right;
            delete current;
            return temp;
        }

        if (!current->right) {
            Node* temp = current->left;
            delete current;
            return temp;
        }

        Node* successorParent = current;
        Node* successor = current->right;

    while (successor->left) {
        successorParent = successor;
        successor = successor->left;
    }

    current->name = successor->name;
    current->product = successor->product;


    if (successorParent == current) {
        successorParent->right = successor->right;
    }   
    else {
        successorParent->left = successor->right;
    }

    delete successor;

    }

    return current;
}
void BST::clear(Node* node)
{
    if (!node)
        return;

    clear(node->left);
    clear(node->right);

    delete node;
}
BST::~BST()
{
    clear(root);
}

