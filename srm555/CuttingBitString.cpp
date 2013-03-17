/* SRM 555 Div 1 Lev 1 AC */
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

class CuttingBitString {
public:
  set<LL> st;
  int dp[55];
  void init() {
    st.clear();
    for (LL t = 1 ; t <= LLINF / 5 ; t *= 5) {
      st.insert(t);
    }
  }
  int getmin(string S) {
    init();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0 ; i < S.size() ; ++i) {
      if (dp[i] < INF && S[i] != '0') {
        LL tmp = 0;
        for (int j = i ; j < S.size() ; ++j) {
          tmp = tmp * 2 + S[j] - '0';
          if (st.count(tmp)) {
            // printf("l:%lld\n",tmp);
            dp[j+1] = min(dp[j+1], dp[i]+1);
          }
        }
      }
    }
    /*
    for (int i = 0 ; i <= S.size() ; ++i)
      printf(" %d", dp[i]);
    printf("\n");
    */
    if (dp[S.size()] >= INF) return -1;
    return dp[S.size()];
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
        CuttingBitString theObject;
        eq(0, theObject.getmin("101101101"),3);
    }
    {
        CuttingBitString theObject;
        eq(1, theObject.getmin("1111101"),1);
    }
    {
        CuttingBitString theObject;
        eq(2, theObject.getmin("00000"),-1);
    }
    {
        CuttingBitString theObject;
        eq(3, theObject.getmin("110011011"),3);
    }
    {
        CuttingBitString theObject;
        eq(4, theObject.getmin("1000101011"),-1);
    }
    {
        CuttingBitString theObject;
        eq(5, theObject.getmin("111011100110101100101110111"),5);
    }
  return 0;
}
// END CUT HERE
