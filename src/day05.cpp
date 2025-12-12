#include "utils.h"

#include <iostream>
#include <fstream>
using namespace std;


static pair<vector<pair<long, long>>, vector<long>> parseInput(vector<string>& input)
{
    pair<vector<pair<long, long>>, vector<long>> output;
    
    int i = 0;
    while (input[i].length() > 0)
    {
        long a = stol(input[i].substr(0, input[i].find('-')));
        long b = stol(input[i].substr(input[i].find('-')+1));
        output.first.push_back(make_pair(a, b));
        i++;
    }
    i++;
    while (i < (int) input.size())
    {
        output.second.push_back(stol(input[i]));
        i++;
    }

    return output;
}


static int partOne()
{
    auto lines = aoc::readLines("input/day05.txt");

    auto ingredients = parseInput(lines);
    int fresh = 0;

    for (const long& id: ingredients.second)
    {
        int j = 0;
        while (j < (int) ingredients.first.size()
                && !(ingredients.first[j].first <= id 
                && id <= ingredients.first[j].second))
        {
            j++;
        }
        
        if (j != (int) ingredients.first.size())
            fresh++;
    }


    return fresh;
}


static pair<long, long> findMinimum(vector<pair<long, long>>& ranges, long level)
{
    pair<long, long> minimum {-1, -1};
    for (auto p: ranges)
    {
        if (minimum.second >= 0)
        {
            if (p.first > level && p.first < minimum.first)
            {
                minimum = p;
            }
        }       
        else if (p.first > level)
        {
            minimum = p;
        } 
    }

    return minimum;
}


static long expandInterval(vector<pair<long, long>>& ranges, long end)
{
    for (auto p: ranges)
    {
        if (p.first <= end && end < p.second)
            return expandInterval(ranges, p.second);
    }

    return end;
}


static long partTwo()
{
    auto lines = aoc::readLines("input/day05.txt");

    auto ranges = parseInput(lines).first;
    long fresh = 0;

    vector<pair<long, long>> reducedRanges;
    pair<long, long> minimum;
    long level = -1;

    do
    {
        minimum = findMinimum(ranges, level);
        if (minimum.second >= 0)
        {
            minimum.second = expandInterval(ranges, minimum.second);
            reducedRanges.push_back(minimum);
            level = minimum.second;
        }
    } 
    while (minimum.second >= 0);

    
    for (auto r: reducedRanges)
    {
        fresh += r.second - r.first + 1;
    }

    return fresh;
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