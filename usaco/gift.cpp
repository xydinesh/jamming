/*
  ID: xydines1
  PROG: gift1
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

using namespace std;

int main() 
{
    vector<string> people;
    string giver;
    string receiver;
    int n;
    int i, j;
    int amount;
    int fri;
    int iamount, rest;

    map <string, int> money;

    freopen ("gift1.in", "r", stdin); freopen ("gift1.out", "w", stdout);

    cin >> n;

    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        people.push_back(s);
        money[people[i]] = 0;
    }

    for (i = 0; i < n; i++)
    {
        amount = 0;
        rest = 0;
        giver.clear ();
        cin >> giver;
        cin >> amount >> fri;
        if (fri > 0)
        {
            iamount = amount/fri;
            rest = amount % fri;
        }
        money[giver] += rest - amount;

        for (j = 0; j < fri; j++)
        {
            receiver.clear ();
            cin >> receiver;
            money[receiver] += iamount;
        }

    }

    for (i = 0; i < n; i++)
    {
        cout << people[i] << " " << money[people[i]] << endl;
    }

    exit (0);
}
