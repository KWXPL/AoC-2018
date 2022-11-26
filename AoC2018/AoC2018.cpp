#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

int twoLetterWord = 0;
int threeLetterWord = 0;

std::string sort(std::string input)
{
	for (unsigned i = 0; i < input.size(); i++)
	{
		for (unsigned j = i + 1; j < input.size(); j++)
		{
			if (input[i] > input[j])
			{
				char tmp = input[i];
				input[i] = input[j];
				input[j] = tmp;
			}
		}
	}
	return input;
}

void findLetters(std::vector <int> lettersInWord)
{
	bool hasTwo = false;
	bool hasThree = false;
	for (unsigned i = 0; i < lettersInWord.size(); i++)
	{
		if (lettersInWord[i] == 2 && !hasTwo)
		{
			hasTwo = true;
			twoLetterWord++;
		}
		else if (lettersInWord[i] == 3 && !hasThree)
		{
			hasThree = true;
			threeLetterWord++;
		}
	}
}

int main()
{
	std::string data;
	std::string tmp;

	std::vector <std::string> inputData;
	std::ifstream input{ "dane.txt" };

	while (input >> data)
	{
		inputData.push_back(data);
	}

	std::cout << "liczenie" << '\n';

	for (unsigned i = 0; i < inputData.size(); i++)
	{
		std::cout << "i = " << i << '\n';
		tmp = inputData[i];
		tmp = sort(tmp);
		int x = 0;
		std::vector <int> lettersInWord;
		for (unsigned j = 1; j < tmp.size(); j++)
		{
			if (tmp[j] == tmp[j - 1])
			{
				lettersInWord[x]++;
			}
			else
			{
				x++;
			}
		}
		findLetters(lettersInWord);
	}
	std::cout << "Checksum = " << twoLetterWord * threeLetterWord;
	return 0;
}
