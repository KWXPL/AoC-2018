#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	int tmp = 0;
	int data;

	std::vector <int> inputData;
	std::vector <int> frequency;
	std::ifstream input{ "Dane1.txt" };

	while (input >> data)
	{
		inputData.push_back(data);
	}

	while (true)
	{
		for (size_t i = 0; i < inputData.size(); i++)
		{
			tmp += inputData[i];
			frequency.push_back(tmp);
			for (size_t j = 0; j < frequency.size(); j++)
			{
				if (j > 0)
				{
					if (tmp == frequency[j - 1])
					{
						std::cout << "frequency: " << tmp << "\n";
						std::cout << "i:" << i << "\n";
						std::cout << "j:" << j << "\n";
						goto exit;
					}
				}
			}
			
		}
	}
exit:
	return 0;
}