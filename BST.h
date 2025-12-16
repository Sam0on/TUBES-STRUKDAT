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
BSTNode* deleteNode(BSTNode* root, int id);
void recommendByGenre(BSTNode* root, const string& genre);
int getMaxID(BSTNode* root);
BSTNode* searchByID(BSTNode* root, int id);
void reindexBST(BSTNode* root, int deletedID);
bool containsDuplicate(BSTNode* root, string title, string artist);
song getRandomSong(BSTNode* root);

#endif
