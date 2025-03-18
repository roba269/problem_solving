/* SRM 556 Div1 Lev2 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define PB push_back
#define MP make_pair
#define SQR(x) ((x)*(x))
#define CLEAR(x) memset((x), 0, sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;

class LeftRightDigitsGame2 {
public:
  int n;
  int dp[52][52];
  inline int match(char a, char b) {
    if (b == '*') return 1;
    return a == b;
  }
  int can(string dig, string pat) {
    CLEAR(dp);
    for (int i = 0 ; i < dig.size() ; ++i) {
      if (match(dig[0], pat[i])) dp[i][i] = 1;
    }
    for (int i = 1 ; i < dig.size() ; ++i) {
      for (int st = 0 ; st < n ; ++st) {
        if (st+i-1 < n && dp[st][st+i-1]) {
          if (st && match(dig[i], pat[st-1]))
            dp[st-1][st+i-1] = 1;
          if (st+i < n && match(dig[i], pat[st+i]))
            dp[st][st+i] = 1;
        }
      }
    }
    // printf("dig:%s pat:%s res:%d\n", dig.c_str(), pat.c_str(), dp[0][n-1]);
    return dp[0][n-1] == 1;
  }
  string minNumber(string dig, string lowerBound) {
    n = dig.size();
    string pat = lowerBound;
    if (can(dig, pat)) return pat;
    int st_dig, i;
    for (i = n - 1 ; i >= 0 ; --i) {
      char ch;
      for (ch = pat[i] + 1 ; ch <= '9' ; ++ch) {
        pat[i] = ch;
        if (can(dig, pat)) break;
      }
      if (ch <= '9') {
        // printf("pat:%s\n", pat.c_str());
        st_dig = i;
        break;
      }
      pat[i] = '*';
    }
    if (i < 0) return "";
    for (int i = st_dig + 1 ; i < n ; ++i) {
      for (char ch = '0' ; ch <= '9' ; ++ch) {
        pat[i] = ch;
        if (can(dig, pat)) break;
      }
    }
    return pat;
  }
};

// BEGIN CUT HERE

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] ) {
  
    {
        LeftRightDigitsGame2 theObject;
        eq(0, theObject.minNumber("565", "556"),"556");
    }
  
    {
        LeftRightDigitsGame2 theObject;
        eq(1, theObject.minNumber("565", "566"),"655");
    }
    
    {
        LeftRightDigitsGame2 theObject;
        eq(2, theObject.minNumber("565", "656"),"");
    }
    {
        LeftRightDigitsGame2 theObject;
        eq(3, theObject.minNumber("9876543210", "5565565565"),"5678943210");
    }
    {
        LeftRightDigitsGame2 theObject;
        eq(4, theObject.minNumber("8016352", "1000000"),"1086352");
    }
    
  return 0;
}
// END CUT HERE
