//DLL.cpp
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


void playSongs(DLLNode* head, Stack& history) {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* current = head;
    int choice;

    // Push initial song
    push(history, current->data);

    while (true) {
        cout << "\n===== Sedang Diputar =====\n";
        cout << "Judul  : " << current->data.title << endl;
        cout << "Artis  : " << current->data.artist << endl;
        cout << "Tahun  : " << current->data.tahun << endl;
        cout << "Durasi : " << current->data.durasi << endl;
        cout << "\nLirik:\n" << current->data.lirik << endl;
        cout << "=========================\n";

        cout << "[1] Prev  |  [2] Next  |  [3] Pause  |  [4] Back\nPilih: ";
        cin >> choice;

        if (choice == 1) {
            current = current->prev;
            push(history, current->data);
        }
        else if (choice == 2) {
            current = current->next;
            push(history, current->data);
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

string normalizeDLL(string s) {
    string res = "";
    for (char c : s) {
        if (!isspace(c)) {
            res += tolower(c);
        }
    }
    return res;
}

void deleteFromPlaylist(DLLNode*& head, string title) {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* current = head;
    string target = normalizeDLL(title);
    bool found = false;

    do {
        if (normalizeDLL(current->data.title) == target) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != head);

    if (!found) {
        cout << "Lagu tidak ditemukan di playlist.\n";
        return;
    }

    if (current->next == head && current->prev == head) {
        delete current;
        head = nullptr;
    } else {
        DLLNode* prevNode = current->prev;
        DLLNode* nextNode = current->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        if (current == head) {
            head = nextNode;
        }
        delete current;
    }
    cout << "Lagu berhasil dihapus dari playlist.\n";
}

