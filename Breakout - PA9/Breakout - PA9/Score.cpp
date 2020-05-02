#include "Score.h"


Score1::Score1(int number)
{
	std::cout << "Enter a name for your score..." << std::endl;
	std::string name;
	std::getline(std::cin, name);

	std::ofstream file;
	file.open("Score.txt", std::ios::app);

    file << name << " " << number << std::endl;
    file.close();
}
