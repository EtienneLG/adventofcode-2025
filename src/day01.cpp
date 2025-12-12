#include "utils.h"

#include <iostream>
#include <fstream>
using namespace std;


static int partOne()
{
    auto lines = aoc::readLines("input/day01.txt");

    int position = 50;
    int zeroPass = 0;

    for (auto movement: lines)
    {
        char code = movement[0];
        int rotation = stoi(movement.substr(1));

        position = (position + (code == 'L' ? -rotation : rotation)) % 100;
        if (position < 0)
            position = 100 + position;

        if (position == 0)
            zeroPass++;
    }

    return zeroPass;
}


static int partTwo()
{
    auto lines = aoc::readLines("input/day01.txt");

    int position = 50;
    int zeroPass = 0;

    for (auto movement: lines)
    {
        char code = movement[0];
        int rotation = stoi(movement.substr(1));

        if (code == 'L' && position - rotation <= 0)
        {
            zeroPass += -((position - rotation) / 100) + (position == 0 ? 0 : 1);
        }
        else if (code == 'R' && rotation + position >= 100)
        {
            zeroPass += (rotation + position) / 100;
        }

        position = (position + (code == 'L' ? -rotation : rotation)) % 100;
        if (position < 0)
            position = 100 + position;
    }
    
    return zeroPass;
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