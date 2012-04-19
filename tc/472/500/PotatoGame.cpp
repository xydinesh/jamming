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
#define SZ(a) (int)(a.size())

using namespace std;

class PotatoGame {

	public:

	string theWinner(int n) {
        int count = 0;
        vector<string> winner;
        pb(winner, "Hanako");
        pb(winner, "Taro");

        while (n > 0)
        {
            count += n % 4;
            n /= 4;
        }
        
        return winner[(count % 2)];
	}

private:
    vector <double> powers;

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "Taro"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "Hanako"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "Taro"; verify_case(2, Arg1, theWinner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE
int main()
{
     PotatoGame ___test; 
      ___test.run_test(-1); 
} 
// END CUT HERE


    
