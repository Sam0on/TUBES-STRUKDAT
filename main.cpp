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
                    cout << "✔ Lagu ditambahkan ke playlist!\n";
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
        }
        else break;
    }

    return 0;
}
