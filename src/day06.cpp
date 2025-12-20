#include "utils.h"

#include <iostream>
#include <fstream>
using namespace std;


static long partOne()
{
    auto lines = aoc::readSpaceLines("input/day06.txt");

    long grandTotal = 0;

    for (size_t i = 0; i < lines.back().size(); i++)
    {
        long result = stol(lines[0][i]);
        bool plus = lines.back()[i][0] == '+';
        for (size_t j = 1; j < lines.size() - 1; j++)
        {
            if (plus)
                result += stol(lines[j][i]);
            else
                result *= stol(lines[j][i]);
        }
        grandTotal += result;
    }

    return grandTotal;
}


static long partTwo()
{
    auto lines = aoc::readSpaceColumns("input/day06.txt");

    long grandTotal = 0;

    for (size_t i = 0; i < lines.back().size(); i++)
    {
        char op = lines.back()[i][0];
        long result = (op == '+' ? 0L : 1L);
        for (size_t j = 0; j < lines[0][i].length(); j++)
        {
            string columnNumber = "";
            for (size_t k = 0; k < lines.size() - 1; k++)
            {
                columnNumber += lines[k][i][j];
            }
            if (op == '+')
                result += stol(columnNumber);
            else
                result *= stol(columnNumber);
        }
        grandTotal += result;
    }

    return grandTotal;
}


int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (*argv[1] == '1')
            cout << partOne();
        else if (*argv[1] == '2')
            cout << partTwo();
        else
            cout << "Error : Type 1 or 2";
    }
    else
        cout << "Error : Enter a part (1 or 2)";
    cout << endl;

    return 0;
}