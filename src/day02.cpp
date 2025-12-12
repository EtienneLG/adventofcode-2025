#include "utils.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


static int lenN(unsigned long n)
{
    int l = 0;
    while (n > 0)
    {
        n /= 10;
        l++;
    }
    return l;
}


static unsigned long nextEvenDigits(int length)
{
    unsigned long even = 1;
    for (int i = 0; i < length; i++)
        even *= 10;
    return even;
}


static unsigned long extractLeft(unsigned long n, int length)
{
    int d = (length % 2 == 0 ? 1 : 10);
    for (int i = 0; i < (length / 2); i++)
        d *= 10;
    
    return (n - (n % d)) / d;
}


static unsigned long reassemble(unsigned long left)
{
    int length = lenN(left);
    unsigned long result = left;
    for (int i = 0; i < length; i++)
        result *= 10;
    
    return result + left;
}


static unsigned long partOne()
{
    auto line = aoc::readCommaLine("input/day02.txt");

    unsigned long invaldIDSum = 0;

    for (auto p: line)
    {
        unsigned long first = stoul(p.first);
        unsigned long last = stoul(p.second);

        int taille = lenN(first);
        unsigned long left = extractLeft(first, taille);
        if (taille % 2 == 1)
            left = nextEvenDigits(taille / 2);
        
        unsigned long miror = reassemble(left);
        while (miror <= last)
        {
            if (miror >= first)
                invaldIDSum += miror;
            left++;
            taille = lenN(miror);
            if (taille % 2 == 1)
                left = nextEvenDigits(taille / 2);
            miror = reassemble(left);
        }
    }

    return invaldIDSum;
}


static unsigned long partTwo()
{
    auto line = aoc::readCommaLine("input/day02.txt");

    unsigned long invaldIDSum = 0;

    for (auto p: line)
    {
        string currentS = p.first;
        
        unsigned long currentI = stoul(currentS);
        unsigned long last = stoul(p.second);

        while (currentI <= last)
        {
            int len = currentS.length();
            for (int i = 1; i <= len / 2; i++)
            {
                if (len % i == 0)
                {
                    int step = i;
                    string sub1 = currentS.substr(0, step);
                    string sub2;
                    int j = step;
                    do
                    {
                        sub2 = currentS.substr(j, step);
                        j += step;
                    } while (sub1 == sub2 && j < len);
                    
                    if (sub1 == sub2 && j >= len)
                    {
                        invaldIDSum += stoul(currentS);
                        break;
                    }
                }
            }
            currentS = to_string(++currentI);
        }
    }

    return invaldIDSum;
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