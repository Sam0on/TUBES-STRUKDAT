// main.cpp
#include <iostream>
#include "BST.h"
#include "DLL.h"
using namespace std;

int main() {
    BSTNode* library;
    DLLNode* playlist;

    createTree(library);
    createList(playlist);

    // Data awal (Dummy Data)
    insertNode(library, {1, "Closer", "The Chainsmokers, Halsey", 2016, "04:04", "Hey, I was doing just fine before I met you\nI drink too much and that's an issue, but I'm okay\nHey, you tell your friends it was nice to meet them\nBut I hope I never see them again"});
    insertNode(library, {2, "The Scientist", "Coldplay", 2010, "05:09", "Nobody said it was easy\nIt's such a shame for us to part\nNobody said it was easy\nNo one ever said it would be this hard\nOh, take me back to the start"});
    insertNode(library, {3, "if u could see me cryin' in my room", "Arash Buana, raissa anggiani", 2020, "04:16", "Hey, I missed you too\nAnd just so you know, I still love you\nAnd I don't even know if I'm alright\n'Cause if I called we'd only end up in a fight\nAnd I don't wanna keep on getting hurt\nStill holding to your favorite little shirt"});
    insertNode(library, {4, "XXL", "LANY", 2023, "03:26", "I still remember, I will forever\nBackseat secrets we won't ever tell, I miss you double XL\nMiss Americana and all my friends love ya\nBack patio at the Bowery Hotel, I miss you double XL"});
    insertNode(library, {5, "The Fate of Ophelia", "Taylor Swift", 2025, "03:46", "Keep it one hundred\nOn the land, the sea, the sky\nPledge allegiance to your hands\nYour team, your vibes"});
    insertNode(library, {6, "So Easy", "Olivia Dean", 2025, "02:49", "'Cause I make it so easy to fall in love\nSo come give me a call, and we'll fall into us\nI'm the perfect mix of Saturday night and the rest of your life\nAnyone with a heart would agree"});
    insertNode(library, {7, "Blue Jeans", "GANGGA", 2020, "03:31", "Sometimes I wish\nThat I could still call you mine\n"});

    int menu, id, tahun;
    string title, artist, durasi, lirik;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            int m;
            cout << "\n=== MENU ADMIN ===\n";
            cout << "1. Tambah Lagu\n";
            cout << "2. Lihat Semua Lagu\n";
            cout << "3. Hapus Lagu\n";
            cout << "Pilih: ";
            cin >> m;

            if (m == 1) {
                cout << "ID Lagu: ";
                cin >> id;
                cin.ignore();

                cout << "Judul Lagu: ";
                getline(cin, title);
                
                cout << "Artis: ";
                getline(cin, artist);

                cout << "Tahun Rilis: ";
                cin >> tahun;
                cin.ignore();

                cout << "Durasi (mm:ss): ";
                getline(cin, durasi);

                cout << "Masukkan Lirik Lagu (akhiri dengan baris kosong):\n";
                string line;
                lirik = "";
                while (true) {
                    getline(cin, line);
                    if (line.empty()) break;
                    lirik += line + "\n";
                }

                song s = {id, title, artist, tahun, durasi, lirik};
                insertNode(library, s);

                cout << "Lagu berhasil ditambahkan!\n";
            }
            else if (m == 2) {
                cout << "\n=== LIST LAGU ===\n";
                inOrder(library);
            }
            else if (m == 3) {
                cin.ignore();
                cout << "Masukkan Judul lagu yang ingin dihapus: ";
                getline(cin, title);
                library = deleteNode(library, title);
                cout << "Lagu dihapus.\n";
            }

        }

        else if (menu == 2) {
            int u;
            cout << "\n=== MENU USER ===\n";
            cout << "1. Cari Lagu\n";
            cout << "2. Tambah Lagu ke Playlist\n";
            cout << "3. Lihat Playlist\n";
            cout << "4. Putar Playlist\n";
            cout << "5. Hapus Lagu dari Playlist\n";
            cout << "Pilih: ";
            cin >> u;

            if (u == 1) {
            cin.ignore();
            cout << "Masukkan Judul Lagu: ";
            getline(cin, title);

            BSTNode* found = searchByTitle(library, title);
            if (found) {
                cout << "Ditemukan: " << found->data.title << " - " << found->data.artist << endl;
                
                int pilihTambah;
                cout << "Tambahkan ke playlist? (1 = ya, 0 = tidak): ";
                cin >> pilihTambah;
                
                if (pilihTambah == 1) {
                    addLast(playlist, found->data);
                    cout << "Lagu ditambahkan ke playlist!\n";
                }
            }
            else {
                cout << "Lagu tidak ditemukan.\n";
            }
        }



            else if (u == 2) {
                cin.ignore();
                cout << "Masukkan Judul Lagu: ";
                getline(cin, title);
                
                BSTNode* found = searchByTitle(library, title);
                if (found) {
                    addLast(playlist, found->data);
                    cout << "Lagu ditambahkan ke playlist.\n";
                } else {
                    cout << "Lagu tidak ditemukan.\n";
                }
            }


            else if (u == 3) {
                cout << "\n=== PLAYLIST ===\n";
                showList(playlist);
            }

            else if (u == 4) {
                playSongs(playlist);
            }
            else if (u == 5) {
                cin.ignore();
                cout << "Masukkan Judul Lagu yang ingin dihapus dari playlist: ";
                getline(cin, title);
                deleteFromPlaylist(playlist, title);
            }
        }
        else break;
    }

    return 0;
}
