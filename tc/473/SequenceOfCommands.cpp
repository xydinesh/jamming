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

class SequenceOfCommands {
	public:
	string whatHappens (vector <string> commands) {
		
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string commands[]         = {"L"};
			string expected__         = "bounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string commands[]         = {"SRSL"};
			string expected__         = "unbounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string commands[]         = {"SSSS","R"};
			string expected__         = "bounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string commands[]         = {"SRSL","LLSSSSSSL","SSSSSS","L"};
			string expected__         = "unbounded";

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string commands[]         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SequenceOfCommands().whatHappens(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
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
