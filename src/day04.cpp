#include "utils.h"

#include <iostream>
#include <fstream>
#include <array>
using namespace std;


static int partOne()
{
    auto lines = aoc::readLines("input/day04.txt");

    int accessibleRolls = 0;

    std::array<std::pair<int,int>, 8> directions {{
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0,  1},
        { 1,  1}, { 1, 0}, { 1, -1},
        { 0, -1}
    }};
    
    for (size_t i = 0; i < lines.size(); i++)
    {
        for (size_t j = 0; j < lines[i].length(); j++)
        {
            if (lines[i][j] == '@')
            {
                int adjacentRolls = 0;
                for (auto p: directions)
                {
                    pair<int, int> dir {i + p.first, j + p.second};
                    if (0 <= dir.first && dir.first < (int) lines.size()
                        && 0 <= dir.second && dir.second < (int) lines[0].length()
                        && lines[dir.first][dir.second] == '@')
                    {
                        adjacentRolls++;
                    }
                }
                if (adjacentRolls < 4)
                    accessibleRolls++;
            }
        }
    }

    return accessibleRolls;
}


static int partTwo()
{
    auto lines = aoc::readLines("input/day04.txt");
    auto nexLines = lines;

    int removedRolls = 0;
    int accessibleRolls;

    do
    {
        accessibleRolls = 0;

        std::array<std::pair<int,int>, 8> directions {{
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0,  1},
            { 1,  1}, { 1, 0}, { 1, -1},
            { 0, -1}
        }};
        
        for (size_t i = 0; i < lines.size(); i++)
        {
            for (size_t j = 0; j < lines[i].length(); j++)
            {
                if (lines[i][j] == '@')
                {
                    int adjacentRolls = 0;
                    for (auto p: directions)
                    {
                        pair<int, int> dir {i + p.first, j + p.second};
                        if (0 <= dir.first && dir.first < (int) lines.size()
                            && 0 <= dir.second && dir.second < (int) lines[0].length()
                            && lines[dir.first][dir.second] == '@')
                        {
                            adjacentRolls++;
                        }
                    }
                    if (adjacentRolls < 4)
                    {
                        nexLines[i][j] = '.';
                        accessibleRolls++;
                    }
                }
            }
        }
        removedRolls += accessibleRolls;
        lines = nexLines;
    }
    while (accessibleRolls > 0);

    return removedRolls;
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