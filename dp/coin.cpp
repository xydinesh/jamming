#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

#define FOR(i, a, b) for(i = a; i < b; i ++)
#define PB(a, b) a.push_back(b)
#define SZ(a) (int)(a.size())
using namespace std;

class Coin {
public:
    string processCoins(int sum, vector<int> coins);
    vector<int> readLine ();
};


string Coin::processCoins(int sum, vector<int> coins)
{
    int i;
    int j;
    char output[100];
    vector<int> table;
    vector<int> min(sum + 1, (INT_MAX - 1));
    vector<int> prev(sum + 1, 0);

    min[0] = 0;
    PB(table, 0);
    FOR(i, 1, sum + 1)
    {
        FOR(j, 0, coins.size())
        {
            if ((i >= coins[j]) && (min[i - coins[j]] + 1 < min[i]))
            {
                min[i] = min[i-coins[j]] + 1;
                prev[i] = i - coins[j];
            }
        }
    }
    sprintf (output, "%d\n", min[sum]);
    return string(output);
}

vector<int> Coin::readLine ()
{
    vector<int> coins;
    char tmp[100];
    unsigned char c;
    int k = 0;

    bzero(tmp, sizeof(char)*100);
    c = getchar();
    while (c != '\n')
    {
        if (c != ' ')
        {
            tmp[k++] = c;
        }
        else
        {
            PB(coins, atoi(tmp));
            bzero(tmp, sizeof(char)*20);
            k = 0;
        }
        c = getchar ();
    }
    PB(coins, atoi(tmp));
    return coins;
}

int main () 
{
    int tc;
    int i;
    int j;
    int k;
    int c;
    int sum;
    int ncoins;
    char tmp[20];
    vector<int> coins;
    string output;

    scanf ("%d\n", &tc);
    FOR(i, 0, tc)
    {
        coins.clear ();
        scanf ("%d %d\n", &sum, &ncoins);
        k = 0;
        Coin *r = new Coin();
        coins = r->readLine ();
        output = r->processCoins (sum, coins);
        cout << "CASE #" << (i + 1) <<": " <<output;
    }
}



