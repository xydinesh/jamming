/*
  ID: xydines1
  PROG: friday
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define PB(a,b) a.push_back(b);
#define RWF(in, out) (freopen(in, "r", stdin), freopen(out, "w", stdout))

using namespace std;

int frist_next_month(int first, int month, int leap)
{
    int ndays;
    if (month == 2)
    {
        ndays = (leap ? 29:28);
    }
    else if ((month == 9) || (month == 4) || (month == 6) || (month == 11))
    {
        ndays = 30;
    }
    else
    {
        ndays = 31;
    }

    return (((ndays % 7) + first) % 7);
}

int find_13 (int first)
{
    return (5 + first)%7;
}


int main() 
{
    int n;
    int i, j;
    int leap = 0;
    vector<int> days (7, 0);
    int first;
    int nfirst;
    int fth;

    RWF("friday.in", "friday.out");
    cin >> n;
    first = 2;
    for (i = 1900; i < 1900 + n; i++)
    {
        leap = 0;
        if (!(i % 4)) leap = 1;
        if (!(i % 100))
        {
            leap = 0;
            if (!(i % 400)) leap = 1;
        }

        for (j = 1; j < 13; j++)
        {
            days[find_13(first)] ++;
            nfirst = frist_next_month(first, j, leap);
            first = nfirst;
        }
    }

    for (i = 0; i < (int)days.size() - 1; i++)
    {
        cout << days[i] << " ";
    }
    cout << days[i] << endl;
    exit (0);
}
