#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
using namespace std;

#include <string>

struct TreeNode {
    string surname;
    string givenName;
    string contactInfo;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(const std::string& last, const std::string& first, const std::string& phone)
        : surname(last), givenName(first), contactInfo(phone), leftChild(nullptr), rightChild(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* search(TreeNode* node, const std::string& last, const std::string& first) const;
    void insert(TreeNode*& node, const std::string& last, const std::string& first, const std::string& phone);
    void display(TreeNode* node) const;
    TreeNode* deleteContact(TreeNode* node, const std::string& last, const std::string& first);
    TreeNode* findMin(TreeNode* node) const;
    void clear(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void addContact(const std::string& last, const std::string& first, const std::string& phone);
    TreeNode* findContact(const std::string& last, const std::string& first) const;
    void removeContact(const std::string& last, const std::string& first);
    void printContacts() const;
};

#endif // BINARYSEARCHTREE_H
