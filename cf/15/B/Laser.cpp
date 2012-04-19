#include <iostream>
#include <cstdio>
#include <cstdlib>

#define FOR(i, a, b) for(i = a; i < b; i ++)

using namespace std;

typedef long long ll;

int main () 
{
    ll tc;
    ll i;
    ll n,m,x1,x2,y1,y2;
    ll x;
    ll y;
    ll ur;
    cin >> tc;
    FOR(i, 0, tc)
    {
        x = 0; y = 0;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        x = n - abs (x1 - x2);
        y = m - abs (y1 - y2);
        ur = n*m  + max((2*x - n), 0LL)*max((2*y - m), 0LL) - 2*x*y;
        cout << ur << endl;
    }
}





