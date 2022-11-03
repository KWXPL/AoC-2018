#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int frequency = 0;
	int number;
	string mark;
	string line;
	ifstream file;

	file.open("Dane1.txt", ios::in);

	if (!file.good())
		cout << "File do not exist";

	while (getline(file, line))
	{
		mark = line.substr(0, 1);
		number = stoi(line.substr(1, line.length()));
		if (mark == "+")
		{
			frequency = frequency + number;
		}
		else
		{
			frequency = frequency - number;
		}
	}
	cout << "frequency: " << frequency << endl;
}
