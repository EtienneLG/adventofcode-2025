#include "utils.h"

#include <fstream>
using namespace std;


vector<string> aoc::readLines(const string &path)
{
    vector<string> lines;
    ifstream file(path);
    string line;

    while(getline(file, line))
        lines.push_back(line);

    return lines;
}

vector<pair<string, string>> aoc::readCommaLine(const string &path)
{
    ifstream file(path);
    vector<pair<string, string>> values;
    string twoPair;

    pair<string, string> p;
    while (getline(file, p.first, '-'))
    {
        getline(file, p.second, ',');
        values.push_back(p);
    }
    
    return values;
}