#include <iostream>
#include "BST.h"
#include "DLL.h"
#include "Stack.h"
using namespace std;

int main() {
    BSTNode* library;
    DLLNode* playlist;
    Stack history;

    createTree(library);
    createList(playlist);
    createStack(history);

    // Data awal (Dummy Data)
    insertNode(library, {1, "Closer", "The Chainsmokers, Halsey", 2016, "04:04", "Pop", "Hey, I was doing just fine before I met you\nI drink too much and that's an issue, but I'm okay\nHey, you tell your friends it was nice to meet them\nBut I hope I never see them again"});
    insertNode(library, {2, "The Scientist", "Coldplay", 2010, "05:09", "Pop", "Nobody said it was easy\nIt's such a shame for us to part\nNobody said it was easy\nNo one ever said it would be this hard\nOh, take me back to the start"});
    insertNode(library, {3, "if u could see me cryin' in my room", "Arash Buana, raissa anggiani", 2020, "04:16", "Indie", "Hey, I missed you too\nAnd just so you know, I still love you\nAnd I don't even know if I'm alright\n'Cause if I called we'd only end up in a fight\nAnd I don't wanna keep on getting hurt\nStill holding to your favorite little shirt"});
    insertNode(library, {4, "XXL", "LANY", 2023, "03:26", "Pop", "I still remember, I will forever\nBackseat secrets we won't ever tell, I miss you double XL\nMiss Americana and all my friends love ya\nBack patio at the Bowery Hotel, I miss you double XL"});
    insertNode(library, {5, "The Fate of Ophelia", "Taylor Swift", 2025, "03:46", "Pop", "Keep it one hundred\nOn the land, the sea, the sky\nPledge allegiance to your hands\nYour team, your vibes"});
    insertNode(library, {6, "So Easy", "Olivia Dean", 2025, "02:49", "R&B",  "'Cause I make it so easy to fall in love\nSo come give me a call, and we'll fall into us\nI'm the perfect mix of Saturday night and the rest of your life\nAnyone with a heart would agree"});
    insertNode(library, {7, "Blue Jeans", "GANGGA", 2020, "03:31", "Pop", "Sometimes I wish\nThat I could still call you mine\n"});
    insertNode(library, {8, "Location Unknown", "HONNE, BEKA", 2018, "05:25", "Pop","Traveling places\nI ain't seen you in ages\nBut I hope you come back to me\nMy mind's running wild\nWith you far away\nI still think of you a hundred times a day"});
    insertNode(library, {9, "Jaran Goyang", "Nella Kharisma", 2017, "04:20", "Dangdut","Jurus yang sangat ampuh teruji terpercaya\nTanpa anjuran dokter tanpa harus muter-muter\nCukup siji solusinya pergi ke mbah dukun saja\nLangsung sambat Mbah saya putus cinta"});
    insertNode(library, {10, "Super", "SEVENTEEN", 2023, "03:20", "K-pop","I love my team, I love my crew\nYeogikkaji dallimyeonseo\nI love my team, I love my crew\nGyesok dallil su isseo deo\nI love my team, I love my crew\nYeogikkaji oreumyeonseo\nI love my team, geu deokbune urin\nMachi doen geot gata sonogong"});
    insertNode(library, {11, "HOT", "SEVENTEEN", 2022, "03:20", "K-pop","Bami eomneun nat haneureun bulgeunsaek\nModeun sesange bicheun hanain deuthae (hana dwen deushi)\nBeokchan shimhoheubgwa rideum gwayeol Vibe\nUnmyeonge taeyange naeireul georeobwa\nTtaraora Go\nUrineun Drop it like HOT HOT HOT"});
    insertNode(library, {12, "Rock with you", "SEVENTEEN", 2021, "03:04", "K-pop","No words are enough for you\nNoraetmallo damgo shipeo\nSSo, modeun naye gamjeong\nNeoro ilkgo sseuge haejweo"});
    insertNode(library, {13, "Kelingan Mantan", "NDX A.K.A", 2024, "03:22", "Dangdut","Dek kowe mbiyen janji karo aku\nNglakoni tresno suci kanthi ikhlas tekan mati\nNeng nyatane ngapusi cidro ati iki\nNetes eluhku mili deres neng pipi"});
    insertNode(library, {14, "Terbuang Dalam Waktu", "Barasuara", 2024, "05:31", "Indie","Melihatmu bersemi dan bermekaran\nTawa candamu berikan kekuatan\nSisa hariku pagi berganti waktu\nMemelukmu"});
    insertNode(library, {15, "Tabola Bale", "Silet Open Up", 2025, "04:35", "Pop","Kaka tabola-bale lia Ade Nona e\nSu makin manyala e, kaka hati susah e\nDulu denai lah suko mancaliak Uda bakawan\nRaso-raso ko ado, tapi denai diamkan (hei!)"});
    insertNode(library, {16, "Kekal", "Nadin Amizah", 2023, "04:41", "Indie","Yang memeluk raga kecilku\nYang menyayangi kecilku\nYang memeluk jiwa kecilku\nDan semua-semua aku"});
    insertNode(library, {17, "Cincin", "Hindia", 2023, "04:26", "Indie","Kau bermasalah jiwa aku pun rada gila\nJodoh akal-akalan neraka kita bersama\nKau langganan menangis lakimu muntah-muntah\nBegitu terus sampai Iblis tobat dan sedekah"});
    insertNode(library, {18, "Nina", ".Feast", 2024, "04:37", "Pop Rock","Aku tahu kamu hebat\nNamun, s'lamanya diriku pasti berkutat\n'Tuk s'lalu jauhkanmu dari dunia yang jahat\nIni sumpahku padamu 'tuk biarkanmu\nTumbuh lebih baik, cari panggilanmu\nJadi lebih baik dibanding diriku"});

    int menu, id, tahun;
    string title, artist, durasi, genre, lirik;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            while (true) {
                int m;
                cout << "\n=== MENU ADMIN ===\n";
                cout << "1. Tambah Lagu\n";
                cout << "2. Lihat Semua Lagu\n";
                cout << "3. Hapus Lagu\n";
                cout << "4. Edit Lagu\n";
                cout << "0. Kembali ke Menu Utama\n";
                cout << "Pilih: ";
                cin >> m;

                if (m == 0) break;

            if (m == 1) {
                id = getMaxID(library) + 1;
                cout << "ID: " << id << endl;
                cin.ignore();


                cout << "Judul: ";
                getline(cin, title);
                
                cout << "Artis: ";
                getline(cin, artist);

                cout << "Tahun Rilis: ";
                cin >> tahun;
                cin.ignore();

                cout << "Durasi (mm:ss): ";
                getline(cin, durasi);

                cout << "Genre: ";
                getline(cin, genre);

                cout << "Masukkan Lirik Lagu (akhiri dengan baris kosong):\n";
                string line;
                lirik = "";
                while (true) {
                    getline(cin, line);
                    if (line.empty()) break;
                    lirik += line + "\n";
                }

                song s = {id, title, artist, tahun, durasi, genre, lirik};
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
            else if (m == 4) {
                 cout << "Masukkan ID Lagu yang ingin diedit: ";
                 cin >> id;
                 cin.ignore();
                 
                 BSTNode* target = searchByID(library, id);
                 if (target) {
                     cout << "Data Lama: " << target->data.title << " - " << target->data.artist << endl;
                     
                     cout << "Judul Baru: ";
                     getline(cin, title);
                     
                     cout << "Artis Baru: ";
                     getline(cin, artist);

                     cout << "Tahun Rilis Baru: ";
                     cin >> tahun;
                     cin.ignore();

                     cout << "Durasi Baru (mm:ss): ";
                     getline(cin, durasi);

                     cout << "Genre Baru: ";
                     getline(cin, genre);

                     cout << "Lirik Baru (akhiri dengan baris kosong):\n";
                     string line;
                     lirik = "";
                     while (true) {
                         getline(cin, line);
                         if (line.empty()) break;
                         lirik += line + "\n";
                     }
                     
                     // Update data
                     target->data.title = title;
                     target->data.artist = artist;
                     target->data.tahun = tahun;
                     target->data.durasi = durasi;
                     target->data.genre = genre;
                     target->data.lirik = lirik;
                     
                     // Update di playlist juga jika ada
                     updateSongInList(playlist, target->data);
                     
                     cout << "Lagu berhasil diupdate!\n";
                 } else {
                     cout << "Lagu dengan ID tersebut tidak ditemukan.\n";
                 }
            }
            }
        }

        else if (menu == 2) {
            int u;
            cout << "\n=== MENU USER ===\n";
            cout << "1. Cari Lagu\n";
            cout << "2. Lihat Playlist (Putar, Tambah, Hapus)\n";
            cout << "3. Lihat Riwayat Lagu\n";
            cout << "4. Rekomendasi Lagu Sesuai Genre\n";
            cout << "0. Kembali ke Menu Utama\n";
            cout << "Pilih: ";
            cin >> u;

            if (u == 1) {
                cin.ignore();
                cout << "Masukkan Judul Lagu: ";
                getline(cin, title);

                BSTNode* found = searchByTitle(library, title);
                if (found) {
                    cout << "Ditemukan: " << found->data.title << " - " << found->data.artist << endl;
                    
                    int opsi;
                    cout << "1. Tambah ke Playlist\n";
                    cout << "2. Putar Langsung\n";
                    cout << "0. Kembali\n";
                    cout << "Pilih: ";
                    cin >> opsi;
                    
                    if (opsi == 1) {
                        addLast(playlist, found->data);
                        cout << "Lagu ditambahkan ke playlist!\n";
                    } else if (opsi == 2) {
                        addLast(playlist, found->data);
                        // Play dari node terakhir (tail)
                        playSongs(playlist, history, playlist->prev); 
                    }
                }
                else {
                    cout << "Lagu tidak ditemukan.\n";
                }
            }
            else if (u == 2) {
                while (true) {
                    cout << "\n=== PLAYLIST SAYA ===\n";
                    showList(playlist);
                    
                    cout << "\nMenu Playlist:\n";
                    cout << "1. Putar Playlist\n";
                    cout << "2. Tambah Lagu ke Playlist\n";
                    cout << "3. Hapus Lagu dari Playlist\n";
                    cout << "0. Kembali ke Menu User\n";
                    cout << "Pilih: ";
                    int p;
                    cin >> p;

                    if (p == 1) {
                        playSongs(playlist, history);
                    } else if (p == 2) {
                         cin.ignore();
                         cout << "Masukkan Judul Lagu yang ingin ditambahkan: ";
                         getline(cin, title);
                         
                         BSTNode* found = searchByTitle(library, title);
                         if (found) {
                             addLast(playlist, found->data);
                             cout << "Lagu berhasil ditambahkan ke playlist.\n";
                         } else {
                             cout << "Lagu tidak ditemukan di library.\n";
                         }
                    } else if (p == 3) {
                         cin.ignore();
                         cout << "Masukkan Judul Lagu yang ingin dihapus: ";
                         getline(cin, title);
                         deleteFromPlaylist(playlist, title);
                    } else if (p == 0) {
                        break;
                    }
                }
            }
            else if (u == 3) {
                cout << "\n=== RIWAYAT LAGU ===\n";
                showHistory(history);
            }
            else if (u == 4) {
                cin.ignore();
                cout << "Masukkan Genre: ";
                getline(cin, genre);
                cout << "\n=== REKOMENDASI LAGU (" << genre << ") ===\n";
                recommendByGenre(library, genre);
            }
        }
        else break;
    }

    return 0;
}
