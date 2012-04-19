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

class Laser{
public:
    Laser (int n, int m, int x1, int y1, int x2, int y2);
    int processField ();
    vector<int> readLine ();
private:
    int _n;
    int _m;
    int _x1;
    int _x2;
    int _y1;
    int _y2;
    int IsaValid(int i, int j);
    int IsbValid(int i, int j);
};


int Laser::IsbValid(int i, int j)
{
    int dx = i - _x2;
    int dy = j - _y2;
    if (((_x1 + dx) < 0) or ((_x1 + dx) > (_n - 1)))
    {
        return 0;
    }
    else if (((_y1 + dy) < 0) or ((_y1 + dy) > (_m - 1)))
    {
        return 0;
    }
    return 1;
}

int Laser::IsaValid(int i, int j)
{
    int dx = i - _x1;
    int dy = j - _y1;
    if (((_x2 + dx) < 0) or ((_x2 + dx) > (_n - 1)))
    {
        return 0;
    }
    else if (((_y2 + dy) < 0) or ((_y2 + dy) > (_m - 1)))
    {
        return 0;
    }
    return 1;
}

Laser::Laser (int n, int m, int x1, int y1, int x2, int y2)
{
    _n = n;
    _m = m;
    _x1 = x1;
    _x2 = x2;
    _y1 = y1;
    _y2 = y2;
}

int Laser::processField()
{
    int i;
    int j;
    int ur = 0;
    FOR(i, 0, _n)
    {
        FOR(j, 0, _m)
        {
            if ((!IsaValid(i,j)) && (!IsbValid(i,j)))
            {
                ur ++;
            }
        }
    }
    return ur;
}

vector<int> Laser::readLine ()
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
    int n,m,x1,x2,y1,y2;
    scanf ("%d\n", &tc);
    FOR(i, 0, tc)
    {
        scanf("%d %d %d %d %d %d\n", &n, &m, &x1, &y1, &x2, &y2);
        Laser *r = new Laser(n, m, x1, y1, x2, y2);
        printf ("%d\n", r->processField());
    }
}



