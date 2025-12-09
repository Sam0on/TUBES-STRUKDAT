// BST.cpp
#include <iostream>
#include <cctype>
#include "BST.h"
using namespace std;

void createTree(BSTNode*& root) {
    root = nullptr;
}

BSTNode* createNode(song data) {
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void insertNode(BSTNode*& root, song data) {
    if (root == nullptr) {
        root = createNode(data);
        return;
    }

    if (data.id < root->data.id)
        insertNode(root->left, data);
    else if (data.id > root->data.id)
        insertNode(root->right, data);
}

string normalize(string s) {
    string res = "";
    for (char c : s) {
        if (!isspace(c)) {
            res += tolower(c);
        }
    }
    return res;
}

string toLowerStr(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

BSTNode* searchByTitle(BSTNode* root, const string& title) {
    if (!root) return nullptr;

    if (normalize(root->data.title) == normalize(title))
        return root;

    BSTNode* left = searchByTitle(root->left, title);
    if (left) return left;

    return searchByTitle(root->right, title);
}

void inOrder(BSTNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data.id << ". " << root->data.title << " - " << root->data.artist << endl;
    inOrder(root->right);
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

BSTNode* deleteNode(BSTNode* root, const string& title) {
    if (root == nullptr) return root;

    if (title < root->data.title)
        root->left = deleteNode(root->left, title);
    else if (title > root->data.title)
        root->right = deleteNode(root->right, title);
    else {
        // node ketemu
        if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }

        BSTNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.title);
    }
    return root;
}
