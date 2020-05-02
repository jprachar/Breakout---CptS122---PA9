#include "Score.h"


Score1::Score1(int number)
{
    std::fstream file("Score.txt");

    file << number;
    file.close();
}
