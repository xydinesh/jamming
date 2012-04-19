#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

#define FOR(i, a, b) for(i = a; i < b; i++)
#define pb(a, b) a.push_back(b)

using namespace std;

class ThreeCardMonte {
	public:
	string position(string swaps);
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "L"; string Arg1 = "L"; verify_case(0, Arg1, position(Arg0)); }
	void test_case_1() { string Arg0 = "REL"; string Arg1 = "M"; verify_case(1, Arg1, position(Arg0)); }
	void test_case_2() { string Arg0 = "RFRFR"; string Arg1 = "R"; verify_case(2, Arg1, position(Arg0)); }
	void test_case_3() { string Arg0 = ""; string Arg1 = "M"; verify_case(3, Arg1, position(Arg0)); }
	void test_case_4() { string Arg0 = "FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL"; string Arg1 = "L"; verify_case(4, Arg1, position(Arg0)); }

// END CUT HERE
 
};


string ThreeCardMonte::position (string swaps)
{
    char state = 'M';
    int i;
    const char *st = swaps.c_str();
    FOR(i, 0, swaps.size())
    {
        switch(st[i]){
            case 'L':
                if (state == 'M')
                {
                    state = 'L';
                }
                else if (state == 'L')
                {
                    state = 'M';
                }
                break;
            case 'R':
                if (state == 'M')
                {
                    state = 'R';
                }
                else if (state == 'R')
                {
                    state = 'M';
                }
                break;
            case 'E':
                if (state == 'L')
                {
                    state = 'R';
                }
                else if (state == 'R')
                {
                    state = 'L';
                }
                break;
            case 'F':
                break;
        };
    }
    return string(&state);
}

// BEGIN CUT HERE
int main()
{
     ThreeCardMonte ___test; 
      ___test.run_test(-1); 
} 
// END CUT HERE

    
