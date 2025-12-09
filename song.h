#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;

struct song {
    int id;
    string title;
    string artist;
    int tahun;        // tahun rilis lagu
    string durasi;    // durasi lagu, contoh "03:45"
    string lirik;     // lirik lagu (panjang)
};

#endif
