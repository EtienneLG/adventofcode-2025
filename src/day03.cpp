#include "utils.h"

#include <iostream>
#include <fstream>
#include <array>
using namespace std;


static int partOne()
{
    auto lines = aoc::readLines("input/day03.txt");

    int joltageSum = 0;

    for (auto battery: lines)
    {
        char& jolt1 = battery[0];
        int jolt1Index = 0;
        for (size_t i = 1; i < battery.length() - 1; i++)
        {
            if (battery[i] > jolt1)
            {
                jolt1 = battery[i];
                jolt1Index = i;
            }
        }

        char& jolt2 = battery[jolt1Index + 1];
        for (size_t i = jolt1Index + 2; i < battery.length(); i++)
        {
            if (i != (size_t) jolt1Index && battery[i] > jolt2)
                jolt2 = battery[i];
        }
        
        joltageSum += (jolt1 - 48)*10 + (jolt2 - 48);
    }

    return joltageSum;
}


static long partTwo()
{
    auto lines = aoc::readLines("input/day03.txt");

    long joltageSum = 0;

    for (auto battery: lines)
    {
        string largest = "";
        int lastJoltIndex = -1;
        for (int i = 0; i < 12; i++)
        {
            lastJoltIndex++;
            char biggest = battery[lastJoltIndex];
            for (size_t j = lastJoltIndex + 1; j < (battery.length() - 12+i+1); j++)
            {
                if (battery[j] > biggest)
                {
                    biggest = battery[j];
                    lastJoltIndex = j;
                }
            }
            largest += biggest;
        }
        joltageSum += stol(largest);
    }

    return joltageSum;
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