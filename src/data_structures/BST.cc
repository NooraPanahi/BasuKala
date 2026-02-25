#include "data_structures/BST.h"
void BST::insertbyname(const std::string& key, Product* value)
{
    if (!root) {
        Node* newnode = new Node;
        newnode->left = newnode->right = nullptr;
        newnode->name = key;
        newnode->productbyname.push_back(value);
        root = newnode;
        return;
    }

    Node* temp = root;
    Node* parent = nullptr;

    while (temp) {
        if (temp->name == key) {
            temp->productbyname.push_back(value);
            return;
        }

        parent = temp;
        
        if (key < temp->name)
            temp = temp->left;
        else
            temp = temp->right;
    }

    Node* newnode = new Node;
    newnode->left = newnode->right = nullptr;
    newnode->name = key;
    newnode->productbyname.push_back(value);

    if (key < parent->name)
        parent->left = newnode;
    else
        parent->right = newnode;
}
void BST::insertbyprice(const std::string& key, Product* value)
{
    if (!root2) {
        Node* newnode = new Node;
        newnode->left = newnode->right = nullptr;
        newnode->name = key;
            newnode->price = value->getPrice();

        newnode->productbyprice.push_back(value);
        root2 = newnode;
        return;
    }

    Node* temp = root2;
    Node* parent = nullptr;

    while (temp) {
        if (temp->price == value->getPrice()) {
            temp->productbyprice.push_back(value);
            return;
        }

        parent = temp;
        
        if (value->getPrice() < temp->price)
            temp = temp->left;
        else
            temp = temp->right;
    }

    Node* newnode = new Node;
    newnode->left = newnode->right = nullptr;
    newnode->name = key;
    newnode->price = value->getPrice();
    newnode->productbyprice.push_back(value);

    if (value->getPrice() < parent->price)
        parent->left = newnode;
    else
        parent->right = newnode;
}
std::vector<Product*>* BST::search(const std::string& key)
{
    Node* current = root;

    while (current) {
        if (key == current->name)
            return &(current->productbyname);
        else if (key < current->name)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}


void BST::remove(const std::string& key, int productId, Product* value)
{
    root = removeHelper(root, key, productId);
    root2 = removeHelperprice(root2, value, productId);
    
    
}

BST::Node* BST::removeHelper(Node* current,
                             const std::string& key,
                             int productId)
{
    if (!current)
        return nullptr;

    if (key < current->name)
        current->left = removeHelper(current->left, key, productId);
    else if (key > current->name)
        current->right = removeHelper(current->right, key, productId);
    else {

        auto& vec = current->productbyname;

        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if ((*it)->getId() == productId) {
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
        current->productbyname = successor->productbyname;

        if (successorParent == current)
            successorParent->right = successor->right;
        else
            successorParent->left = successor->right;

        delete successor;
    }

    return current;
}

BST::Node* BST::removeHelperprice(Node* current,
                             Product* value,
                             int productId)
{
    if (!current)
        return nullptr;

    if (value->getPrice() < current->price)
        current->left = removeHelperprice(current->left, value, productId);
    else if (value->getPrice() > current->price)
        current->right = removeHelperprice(current->right, value, productId);
    else {

        auto& vec = current->productbyprice;

        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if ((*it)->getId() == productId) {
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
        current->price = successor->price;
        current->productbyprice = successor->productbyprice;

        if (successorParent == current)
            successorParent->right = successor->right;
        else
            successorParent->left = successor->right;

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
    clear(root2);
}

BST::Node* BST::getNode() {
    return root;
}
void BST::printProducts(bool nameOrprice) const
{
    if(nameOrprice){
        printNode(root);
    }
    else{
        printbyprice(root2);
    }
}
void BST::printbyprice(Node* node) const{
        if(!node) return;
    printbyprice(node->left);
    for(auto prod : node->productbyprice){
        std::cout << "Product ID: " << prod->getId()
                  << ", " << prod->getName()
                  << ", $" << prod->getPrice() << '\n';
    }
    printbyprice(node->right);
}
void BST::printNode(Node *node) const
{
    if(!node) return;
    printNode(node->left);
    for(auto prod : node->productbyname){
        std::cout << "Product ID: " << prod->getId()
                  << ", " << prod->getName()
                  << ", $" << prod->getPrice() << '\n';
    }
    printNode(node->right);
}


void BST::insert(const std::string &key, Product *value)
{
    insertbyname(key, value);
    insertbyprice(key, value);
}
