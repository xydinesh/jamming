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

class RockStar {
	public:
	int getNumSongs (int ff, int fs, int sf, int ss) {
        int count = 0;

        if (ff > 0 || fs > 0)
        {
            if (sf >= fs)
            {
                count = 2*fs + ff;
                if (sf > 0) count += ss;
            }
            else
            {
                count = 2*sf + ff + ss + 1;
            }
        }
        else
        {
            count = ss;
            count += (sf > 0);
        }

        return count;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int ff                    = 100;
			int fs                    = 0;
			int sf                    = 0;
			int ss                    = 200;
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int ff                    = 0;
			int fs                    = 0;
			int sf                    = 20;
			int ss                    = 200;
			int expected__            = 201;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int ff                    = 1;
			int fs                    = 2;
			int sf                    = 1;
			int ss                    = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int ff                    = 192;
			int fs                    = 279;
			int sf                    = 971;
			int ss                    = 249;
			int expected__            = 999;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

     case 4: {
			int ff                    = 10;
			int fs                    = 10;
			int sf                    = 10;
			int ss                    = 10;
			int expected__            = 40;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
     case 5: {
			int ff                    = 0;
			int fs                    = 0;
			int sf                    = 100;
			int ss                    = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int ff                    = ;
			int fs                    = ;
			int sf                    = ;
			int ss                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RockStar().getNumSongs(ff, fs, sf, ss);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
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
