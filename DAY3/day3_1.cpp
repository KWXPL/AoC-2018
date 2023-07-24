#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ZarezerwowanyObszar {
public:
    unsigned int  id, x, y, s, w;

    ZarezerwowanyObszar(int id, int x, int y, int s, int w) : id(id), x(x), y(y), s(s), w(w) {};
};

int main() {

    string line;
    unsigned int id, x, y, s, w;
    unsigned int s_max = 0;
    unsigned int w_max = 0;
    unsigned int zduplikowanyObszar = 0;

    vector<ZarezerwowanyObszar> zObszary;

    ifstream file;
    file.open("dane3_1.txt",ios::in);
    if (!file.good())
        std::cout << "Plik nie istnieje";
    
    while (getline(file, line)) {
        const char* dane = line.c_str();
        sscanf(dane, "#%d @ %d,%d: %dx%d", &id, &x, &y, &s, &w);
        zObszary.push_back(ZarezerwowanyObszar(id, x, y, s, w));
        if (s_max < x + s)
            s_max = x + s;
        if (w_max < y + w)
            w_max = y + w;
    }

    int** obszar = new int*[s_max];
    for (unsigned int i = 0; i < s_max; ++i) {
        obszar[i] = new int[w_max];
    }

    for (unsigned int i = 0; i < s_max; i++) {
        for (unsigned int j = 0; j < w_max; j++) {
            obszar[i][j] = 0;
        }  
    }

    for (unsigned int i = 0; i < zObszary.size(); i++) {
        for (unsigned int j = zObszary[i].x; j < zObszary[i].x + zObszary[i].s; j++) {
            for (unsigned int k = zObszary[i].y; k < zObszary[i].y + zObszary[i].w; k++) {
                obszar[j][k] += 1;
            }  
        }
    }

    for (unsigned int i = 0; i < s_max; i++) {
        for (unsigned int j = 0; j < w_max; j++) {
            if (obszar[i][j] > 1) {
                zduplikowanyObszar += 1;
            }
        }  
    }

    cout << "zduplikowanyObszar = " << zduplikowanyObszar;

    return 0;
}

