//Stack.cpp
#include <iostream>
#include "Stack.h"
using namespace std;

void createStack(Stack& S) {
    S.top = nullptr;
}

void push(Stack& S, song data) {
    StackNode* newNode = new StackNode;
    newNode->data = data;
    newNode->next = S.top;
    S.top = newNode;
}

void showHistory(Stack S) {
    if (S.top == nullptr) {
        cout << "(Riwayat kosong)\n";
        return;
    }

    StackNode* temp = S.top;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->data.title << " - " << temp->data.artist << endl;
        temp = temp->next;
        i++;
    }
}
