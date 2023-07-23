#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

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
    bool p1, p2 = false;

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

    const unsigned int s_maxC = s_max;
    const unsigned int w_maxC = w_max;

    cout << "s_maxC = " << s_maxC << "\n";
    cout << "w_maxC = " << w_maxC << "\n";

    int** obszar = new int*[s_max];
    for (unsigned int i = 0; i < s_max; ++i) {
        obszar[i] = new int[w_max];
    }

    for (unsigned int i = 0; i < s_maxC; i++) {
        for (unsigned int j = 0; j < w_maxC; j++) {
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

    for (unsigned int i = 0; i < zObszary.size(); i++) {
        for (unsigned int j = zObszary[i].x; j < zObszary[i].x + zObszary[i].s; j++) {
            for (unsigned int k = zObszary[i].y; k < zObszary[i].y + zObszary[i].w; k++) {
                if (obszar[j][k] > 1) {
                    p1 = false;
                    break;
                }
                p1 = true;
            } 
            if (p1 == false) {
                p2 = false;
                break;
            }
            p2 = true;
        }
        if (p1 == true && p2 == true) {
            cout << "Odpowiedz: " << zObszary[i].id;
            break;
        }
    }

    return 0;
}

