// DLL.cpp
#include <iostream>
#include "DLL.h"
using namespace std;

void createList(DLLNode*& head) {
    head = nullptr;
}

DLLNode* createDLLNode(song data) {
    DLLNode* newNode = new DLLNode;
    newNode->data = data;
    newNode->next = newNode->prev = nullptr;
    return newNode;
}

void addLast(DLLNode*& head, song data) {
    DLLNode* newNode = createDLLNode(data);

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    DLLNode* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}


void showList(DLLNode* head) {
    if (!head) {
        cout << "(Playlist kosong)\n";
        return;
    }

    DLLNode* temp = head;
    do {
        cout << temp->data.id << ". " 
             << temp->data.title << " - " 
             << temp->data.artist << endl;
        temp = temp->next;
    } while (temp != head);
}


void playSongs(DLLNode* head) {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* current = head;
    int choice;

    while (true) {
        cout << "\n===== Sedang Diputar =====\n";
        cout << "Judul  : " << current->data.title << endl;
        cout << "Artis  : " << current->data.artist << endl;
        cout << "Tahun  : " << current->data.tahun << endl;
        cout << "Durasi : " << current->data.durasi << endl;
        cout << "\nLirik:\n" << current->data.lirik << endl;
        cout << "=========================\n";

        cout << "[1] Next  |  [2] Prev  |  [3] Pause  |  [4] Back\nPilih: ";
        cin >> choice;

        if (choice == 1) {
            current = current->next;
        }
        else if (choice == 2) {
            current = current->prev;
        }
        else if (choice == 3) {
            cout << "Lagu sedang di pause...\n";
            system("pause");
        }
        else if (choice == 4) {
            break;
        }
    }
}

