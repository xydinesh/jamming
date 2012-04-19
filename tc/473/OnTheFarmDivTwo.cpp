#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#define fr(i, a, b) for(i = a; i < b; i++)
#define pb(a, b) a.push_back(b)
#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())

using namespace std;

class OnTheFarmDivTwo {
	public:
	vector <int> animals (int heads, int legs) {
        vector<int> animals;

        if (legs % 2 != 0)
        {
            return animals;
        }

        int cows = (legs/2 - heads);
        int chick = (heads - cows);

        if ((cows >= 0) && (chick >= 0))
        {
            pb(animals, chick);
            pb(animals, cows);
        }
        return animals;
	}
};

// BEGIN CUT HERE

namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int heads                 = 3;
			int legs                  = 8;
			int expected__[]          = {2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int heads                 = 10;
			int legs                  = 40;
			int expected__[]          = {0, 10 };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int heads                 = 10;
			int legs                  = 42;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int heads                 = 1;
			int legs                  = 3;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int heads                 = 0;
			int legs                  = 0;
			int expected__[]          = {0, 0 };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

     case 5: {
			int heads                 = 2;
			int legs                  = 4;
			int expected__[]          = {2, 0};

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
     case 6: {
			int heads                 = 2;
			int legs                  = 0;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
     case 7: {
			int heads                 = 101 ;
			int legs                  = 204 ;
			int expected__[]          = {100, 1 };

			clock_t start__           = clock();
			vector <int> received__   = OnTheFarmDivTwo().animals(heads, legs);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

// END CUT HERE
