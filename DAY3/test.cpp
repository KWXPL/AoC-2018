#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct ZarezerwowanyObszar {
    unsigned int id, x, y, s, w;

    ZarezerwowanyObszar(int id, int x, int y, int s, int w) : id(id), x(x), y(y), s(s), w(w) {}
};

int main() {
    std::string line;
    unsigned int id, x, y, s, w;
    unsigned int s_max = 0;
    unsigned int w_max = 0;
    unsigned int zduplikowanyObszar = 0;

    std::vector<ZarezerwowanyObszar> zObszary;

    std::ifstream file("dane3_1.txt");
    if (!file.good()) {
        std::cout << "Plik nie istnieje";
        return 1;
    }

    while (getline(file, line)) {
        if (sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &id, &x, &y, &s, &w) == 5) {
            zObszary.emplace_back(id, x, y, s, w);
            if (s_max < x + s)
                s_max = x + s;
            if (w_max < y + w)
                w_max = y + w;
        }
    }

    std::vector<std::vector<int>> obszar(s_max, std::vector<int>(w_max, 0));

    for (const auto& zObszar : zObszary) {
        for (unsigned int j = zObszar.x; j < zObszar.x + zObszar.s; j++) {
            for (unsigned int k = zObszar.y; k < zObszar.y + zObszar.w; k++) {
                obszar[j][k] += 1;
            }
        }
    }

    for (const auto& row : obszar) {
        for (int value : row) {
            if (value > 1) {
                zduplikowanyObszar += 1;
            }
        }
    }

    std::cout << "zduplikowanyObszar = " << zduplikowanyObszar << std::endl;

    return 0;
}