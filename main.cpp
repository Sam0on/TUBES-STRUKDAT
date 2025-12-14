// main.cpp
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

    insertNode(library, {1, "Closer", "The Chainsmokers, Halsey", 2016, "04:04", "Hey, I was doing just fine before I met you\nI drink too much and that's an issue, but I'm okay\nHey, you tell your friends it was nice to meet them\nBut I hope I never see them again"});
    insertNode(library, {2, "The Scientist", "Coldplay", 2010, "05:09", "Nobody said it was easy\nIt's such a shame for us to part\nNobody said it was easy\nNo one ever said it would be this hard\nOh, take me back to the start"});
    insertNode(library, {3, "if u could see me cryin' in my room", "Arash Buana, raissa anggiani", 2020, "04:16", "Hey, I missed you too\nAnd just so you know, I still love you\nAnd I don't even know if I'm alright\n'Cause if I called we'd only end up in a fight\nAnd I don't wanna keep on getting hurt\nStill holding to your favorite little shirt"});
    insertNode(library, {4, "XXL", "LANY", 2023, "03:26", "I still remember, I will forever\nBackseat secrets we won't ever tell, I miss you double XL\nMiss Americana and all my friends love ya\nBack patio at the Bowery Hotel, I miss you double XL"});
    insertNode(library, {5, "The Fate of Ophelia", "Taylor Swift", 2025, "03:46", "Keep it one hundred\nOn the land, the sea, the sky\nPledge allegiance to your hands\nYour team, your vibes"});
    insertNode(library, {6, "So Easy", "Olivia Dean", 2025, "02:49", "'Cause I make it so easy to fall in love\nSo come give me a call, and we'll fall into us\nI'm the perfect mix of Saturday night and the rest of your life\nAnyone with a heart would agree"});
    insertNode(library, {7, "Blue Jeans", "GANGGA", 2020, "03:31", "Sometimes I wish\nThat I could still call you mine\n"});
    insertNode(library, {8, "Location Unknown", "HONNE, BEKA", 2018, "05:25", "Traveling places\nI ain't seen you in ages\nBut I hope you come back to me\nMy mind's running wild\nWith you far away\nI still think of you a hundred times a day"});
    insertNode(library, {9, "Jaran Goyang", "Nella Kharisma", 2017, "04:20", "Jurus yang sangat ampuh teruji terpercaya\nTanpa anjuran dokter tanpa harus muter-muter\nCukup siji solusinya pergi ke mbah dukun saja\nLangsung sambat Mbah saya putus cinta"});
    insertNode(library, {10, "Super", "SEVENTEEN", 2023, "03:20", "I love my team, I love my crew\nYeogikkaji dallimyeonseo\nI love my team, I love my crew\nGyesok dallil su isseo deo\nI love my team, I love my crew\nYeogikkaji oreumyeonseo\nI love my team, geu deokbune urin\nMachi doen geot gata sonogong"});
    insertNode(library, {11, "HOT", "SEVENTEEN", 2022, "03:20", "Bami eomneun nat haneureun bulgeunsaek\nModeun sesange bicheun hanain deuthae (hana dwen deushi)\nBeokchan shimhoheubgwa rideum gwayeol Vibe\nUnmyeonge taeyange naeireul georeobwa\nTtaraora Go\nUrineun Drop it like HOT HOT HOT"});
    insertNode(library, {12, "Rock with you", "SEVENTEEN", 2021, "03:04", "No words are enough for you\nNoraetmallo damgo shipeo\nSSo, modeun naye gamjeong\nNeoro ilkgo sseuge haejweo"});
    insertNode(library, {13, "Kelingan Mantan", "NDX A.K.A", 2024, "03:22", "Dek kowe mbiyen janji karo aku\nNglakoni tresno suci kanthi ikhlas tekan mati\nNeng nyatane ngapusi cidro ati iki\nNetes eluhku mili deres neng pipi"});
    insertNode(library, {14, "Terbuang Dalam Waktu", "Barasuara", 2024, "05:31", "Melihatmu bersemi dan bermekaran\nTawa candamu berikan kekuatan\nSisa hariku pagi berganti waktu\nMemelukmu"});
    insertNode(library, {15, "Tabola Bale", "Silet Open Up", 2025, "04:35", "Kaka tabola-bale lia Ade Nona e\nSu makin manyala e, kaka hati susah e\nDulu denai lah suko mancaliak Uda bakawan\nRaso-raso ko ado, tapi denai diamkan (hei!)"});
    insertNode(library, {16, "Kekal", "Nadin Amizah", 2023, "04:41", "Yang memeluk raga kecilku\nYang menyayangi kecilku\nYang memeluk jiwa kecilku\nDan semua-semua aku"});
    insertNode(library, {17, "Cincin", "Hindia", 2023, "04:26", "Kau bermasalah jiwa aku pun rada gila\nJodoh akal-akalan neraka kita bersama\nKau langganan menangis lakimu muntah-muntah\nBegitu terus sampai Iblis tobat dan sedekah"});
    insertNode(library, {18, "Nina", ".Feast", 2024, "04:37", "Aku tahu kamu hebat\nNamun, s'lamanya diriku pasti berkutat\n'Tuk s'lalu jauhkanmu dari dunia yang jahat\nIni sumpahku padamu 'tuk biarkanmu\nTumbuh lebih baik, cari panggilanmu\nJadi lebih baik dibanding diriku"});

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
            cout << "6. Lihat Riwayat Lagu\n";
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
                playSongs(playlist, history);
            }
            else if (u == 5) {
                cin.ignore();
                cout << "Masukkan Judul Lagu yang ingin dihapus dari playlist: ";
                getline(cin, title);
                deleteFromPlaylist(playlist, title);
            }
            else if (u == 6) {
                cout << "\n=== RIWAYAT LAGU ===\n";
                showHistory(history);
            }
        }
        else break;
    }

    return 0;
}
