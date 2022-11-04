#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int frequency = 0;
	int number;
	int *tab;
	int i = 0;
	string mark;
	string line;
	ifstream file;

	tab = new int[1000];

	file.open("Dane1.txt", ios::in);

	if (!file.good())
		cout << "File do not exist";

	while (true)
	{
		while (getline(file, line))
		{
			cout << "line: " << line << endl;
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

			for (int x = 0; x < i; x++)
			{

			}
			i++;
		}
		file.clear();
		file.seekg(0);
	}
	
	cout << "frequency: " << frequency << endl;
}
