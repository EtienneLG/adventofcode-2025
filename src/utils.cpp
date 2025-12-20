#include "utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
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


vector<vector<string>> aoc::readSpaceLines(const string &path)
{
    ifstream file(path);
    vector<vector<string>> lines;

    int l = -1;
    string line;
    while (getline(file, line))
    {
        lines.push_back(vector<string>{}); 
        l++;

        stringstream ss(line);
        string n;
        while (getline(ss, n, ' '))
        {
            if (n.length() > 0)
                lines[l].push_back(n);
        }
    }

    return lines;
}


vector<vector<string>> aoc::readSpaceColumns(const string &path)
{
    ifstream file(path);
    vector<string> lines;
    vector<vector<string>> columns;

    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
        columns.push_back(vector<string>{});
    }

    size_t l = 0;
    for (size_t k = 0; k < columns.size() - 1; k++)
    {
        columns[k].push_back(string());
    }
    columns.back().push_back(string{lines.back()[0]});

    size_t i = 0;
    while (i < lines[0].length())
    {
        bool isSpace = true;
        size_t j = 0;
        while (j < lines.size() - 1)
        {
            if (lines[j][i] != ' ')
            {
                isSpace = false;
            }
            columns[j][l] += lines[j][i];
            j++;
        }
        if (isSpace)
        {
            for (size_t k = 0; k < columns.size() - 1; k++)
            {
                columns[k].back().pop_back();
                columns[k].push_back(string());
            }
            columns.back().push_back(string{lines[j][i+1]});
            l++;
        }
        i++;
    }

    return columns;
}