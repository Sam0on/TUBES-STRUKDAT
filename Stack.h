#ifndef STACK_H
#define STACK_H

#include "song.h"

struct StackNode {
    song data;
    StackNode* next;
};

struct Stack {
    StackNode* top;
};

void createStack(Stack& S);
void push(Stack& S, song data);
void showHistory(Stack S);

#endif
