// BST.h
#ifndef BST_H
#define BST_H

#include "song.h"

struct BSTNode {
    song data;
    BSTNode* left;
    BSTNode* right;
};

void createTree(BSTNode*& root);
BSTNode* createNode(song data);
void insertNode(BSTNode*& root, song data);
string toLowerStr(string s);
BSTNode* searchByTitle(BSTNode* root, const string& title);
void inOrder(BSTNode* root);
BSTNode* minValueNode(BSTNode* node);
BSTNode* deleteNode(BSTNode* root, const string& title);

#endif
