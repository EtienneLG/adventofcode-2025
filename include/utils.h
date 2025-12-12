#if ! defined UTILS_H

#include <string>
#include <vector>
using namespace std;


namespace aoc
{
    vector<string> readLines(const string &path);
    vector<pair<string, string>> readCommaLine(const string &path);
}

#endif // UTILS_H