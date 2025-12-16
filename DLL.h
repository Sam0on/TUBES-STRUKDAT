// DLL.h
#ifndef DLL_H
#define DLL_H

#include "song.h"

#include "Stack.h"

struct DLLNode {
    song data;
    DLLNode* next;
    DLLNode* prev;
};

void createList(DLLNode*& head);
DLLNode* createDLLNode(song data);
void addLast(DLLNode*& head, song data);
void showList(DLLNode* head);
void updateSongInList(DLLNode* head, song newData);
void playSongs(DLLNode* head, Stack& history, DLLNode* startNode = nullptr);
void deleteFromPlaylist(DLLNode*& head, string title);

#endif
