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
void playSongs(DLLNode* head, Stack& history);
void deleteFromPlaylist(DLLNode*& head, string title);

#endif
