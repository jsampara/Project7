#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

// Private Methods
void BinarySearchTree::insert(TreeNode*& node, const std::string& last, const std::string& first, const std::string& phone) {
    if (!node) {
        node = new TreeNode(last, first, phone);
    } else if (last < node->surname || (last == node->surname && first < node->givenName)) {
        insert(node->leftChild, last, first, phone);
    } else {
        insert(node->rightChild, last, first, phone);
    }
}

TreeNode* BinarySearchTree::search(TreeNode* node, const std::string& last, const std::string& first) const {
    if (!node || (node->surname == last && node->givenName == first)) {
        return node;
    } else if (last < node->surname || (last == node->surname && first < node->givenName)) {
        return search(node->leftChild, last, first);
    } else {
        return search(node->rightChild, last, first);
    }
}

TreeNode* BinarySearchTree::deleteContact(TreeNode* node, const std::string& last, const std::string& first) {
    if (!node) return nullptr;

    if (last < node->surname || (last == node->surname && first < node->givenName)) {
        node->leftChild = deleteContact(node->leftChild, last, first);
    } else if (last > node->surname || (last == node->surname && first > node->givenName)) {
        node->rightChild = deleteContact(node->rightChild, last, first);
    } else {
        if (!node->leftChild) {
            TreeNode* temp = node->rightChild;
            delete node;
            return temp;
        } else if (!node->rightChild) {
            TreeNode* temp = node->leftChild;
            delete node;
            return temp;
        } else {
            TreeNode* successor = findMin(node->rightChild);
            node->surname = successor->surname;
            node->givenName = successor->givenName;
            node->contactInfo = successor->contactInfo;
            node->rightChild = deleteContact(node->rightChild, successor->surname, successor->givenName);
        }
    }
    return node;
}

TreeNode* BinarySearchTree::findMin(TreeNode* node) const {
    while (node && node->leftChild) {
        node = node->leftChild;
    }
    return node;
}

void BinarySearchTree::display(TreeNode* node) const {
    if (node) {
        display(node->leftChild);
        std::cout << node->surname << ", " << node->givenName << ": " << node->contactInfo << "\n";
        display(node->rightChild);
    }
}

void BinarySearchTree::clear(TreeNode* node) {
    if (node) {
        clear(node->leftChild);
        clear(node->rightChild);
        delete node;
    }
}

// Public Methods
void BinarySearchTree::addContact(const std::string& last, const std::string& first, const std::string& phone) {
    insert(root, last, first, phone);
}

TreeNode* BinarySearchTree::findContact(const std::string& last, const std::string& first) const {
    return search(root, last, first);
}

void BinarySearchTree::removeContact(const std::string& last, const std::string& first) {
    root = deleteContact(root, last, first);
}

void BinarySearchTree::printContacts() const {
    display(root);
}
