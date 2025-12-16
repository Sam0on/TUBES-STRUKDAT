// DLL.cpp
#include <iostream>
#include "DLL.h"
#include "BST.h"
#include <cstdlib>
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
        cout << temp->data.title << " - " 
             << temp->data.artist << endl;
        temp = temp->next;
    } while (temp != head);
}


void updateSongInList(DLLNode* head, song newData) {
    if (!head) return;
    DLLNode* current = head;
    do {
        if (current->data.id == newData.id) {
            current->data = newData;
        }
        current = current->next;
    } while (current != head);
}

void playSongs(DLLNode* head, Stack& history, DLLNode* startNode) {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* current = startNode ? startNode : head;
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

    // Jika satu-satunya node
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

void reindexDLL(DLLNode* head, int deletedID) {
    if (!head) return;
    
    DLLNode* current = head;
    do {
        if (current->data.id > deletedID) {
            current->data.id--;
        }
        current = current->next;
    } while (current != head);
}

void playStandalone(song startSong, BSTNode* library, Stack& history) {
    song currentSong = startSong;
    int choice;

    // Push first song
    push(history, currentSong);

    while (true) {
        cout << "\n===== Putar Langsung (Standalone) =====\n";
        cout << "Judul  : " << currentSong.title << endl;
        cout << "Artis  : " << currentSong.artist << endl;
        cout << "Tahun  : " << currentSong.tahun << endl;
        cout << "Durasi : " << currentSong.durasi << endl;
        cout << "\nLirik:\n" << currentSong.lirik << endl;
        cout << "======================================\n";
        cout << "(Next/Prev akan memutar lagu acak dari Library)\n";

        cout << "[1] Prev  |  [2] Next  |  [3] Pause  |  [4] Back\nPilih: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
             // Random play logic
             currentSong = getRandomSong(library);
             push(history, currentSong);
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
