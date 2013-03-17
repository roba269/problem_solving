/* SRM 557 Div 1 Lev 1 */
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

class FoxAndMountainEasy {
public:
  string possible(int n, int h0, int hn, string str) {
    int mint = 0;
    for (int i = 0 ; i < str.size() ; ++i) {
      if (str[i] == 'U') ++h0;
      else --h0;
      if (h0 < mint) mint = h0;
    }
    n -= str.size();
    if (mint < 0) {
      n -= -mint;
      h0 += -mint;
    }
    if (n < 0) return "NO";
    if (n < abs(hn - h0)) return "NO";
    if ((n ^ abs(hn-h0)) % 2 == 0) return "YES";
    return "NO";
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
        FoxAndMountainEasy theObject;
        eq(0, theObject.possible(4, 0, 4, "UU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(1, theObject.possible(4, 0, 4, "D"),"NO");
    }
    {
        FoxAndMountainEasy theObject;
        eq(2, theObject.possible(4, 100000, 100000, "DDU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(3, theObject.possible(4, 0, 0, "DDU"),"NO");
    }
    {
        FoxAndMountainEasy theObject;
        eq(4, theObject.possible(20, 20, 20, "UDUDUDUDUD"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(5, theObject.possible(20, 0, 0, "UUUUUUUUUU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(6, theObject.possible(20, 0, 0, "UUUUUUUUUUU"),"NO");
    }
  return 0;
}
// END CUT HERE
