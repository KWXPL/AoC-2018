#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

class Obserwacja {
public:
    long long int id;
    int miesiac, dzien, minuta;
    string dane;

    Obserwacja(long long int id, int miesiac, int dzien, int minuta, string dane) :id(id), miesiac(miesiac), dzien(dzien), minuta(minuta), dane(dane) {};
};

class Zmiana {
    
};

class straznik {

};

void sortowanieBombelkowe(unsigned int rozmiar, vector <Obserwacja> &obserwacje) {
    unsigned int zmiany;

    while(true) {
        zmiany = 0;
        for(unsigned int i = 0; i < rozmiar; i++) {
            if(obserwacje[i].id > obserwacje[i++].id){
                swap(obserwacje[i], obserwacje[i++]);
                zmiany++;
            }
        }
        if(zmiany == 0){
            break;
        }
    }
}

int main() {

    cout << "Plik\n";
    long long int data;
    int rozmiar;
    string id, rok, miesiac, dzien, godzina, minuta;
    string line, dane;
	vector <Obserwacja> obserwacje;
    regex pattern(R"(\[(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2})\] (.+))");
    smatch matches;

    ifstream file;
    file.open("dane_test.txt",ios::in);
    if(!file.good())
        cout << "Plik nie istnieje";

    while(getline(file, line)) {
        if (regex_search(line, matches, pattern)) {
            miesiac = matches[2];
            dzien = matches[3];
            minuta = matches[5];
            dane = matches[6];
        }
        id = miesiac + dzien + minuta;

        obserwacje.push_back(Obserwacja(stoll(id), stoi(miesiac), stoi(dzien), stoi(minuta), dane));
    }

    rozmiar = obserwacje.size();
    cout << "Sortowanie\n";
    sortowanieBombelkowe(rozmiar, obserwacje);
    
    for(int i = 0; i < rozmiar; i++) {
        cout << obserwacje[i].id << "   " << obserwacje[i].dane << "\n";
    }



    return 0;
}