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

class HyperKnight {
public:
  long long countCells(int a, int b, int R, int C, int k) {
    if (a > b) swap(a, b);
    LL res = 0;
    if (k == 2) {
      res = (LL)a * a * 4; 
    }
    if (k == 3) {
      res = (LL)a * (b-a) * 8;
    }
    if (k == 4) {
      res = ((LL)a * (R - 2 * b) + (LL)a * (C - 2 * b)) * 2 + (LL)(b-a) * (b-a) * 4;
    }
    if (k == 6) {
      res = ((LL)(R - 2 * b) * (b-a) + (LL)(C - 2 * b) * (b-a)) * 2;
    }
    if (k == 8) {
      res = (LL)(R - 2 * b) * (C - 2 * b);
    }
    return res;
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
        HyperKnight theObject;
        eq(0, theObject.countCells(2, 1, 8, 8, 4),20LL);
    }
    {
        HyperKnight theObject;
        eq(1, theObject.countCells(3, 2, 8, 8, 2),16LL);
    }
    {
        HyperKnight theObject;
        eq(2, theObject.countCells(1, 3, 7, 11, 0),0LL);
    }
    {
        HyperKnight theObject;
        eq(3, theObject.countCells(3, 2, 10, 20, 8),56LL);
    }
    {
        HyperKnight theObject;
        eq(4, theObject.countCells(1, 4, 100, 10, 6),564LL);
    }
    {
        HyperKnight theObject;
        eq(5, theObject.countCells(2, 3, 1000000000, 1000000000, 8),999999988000000036LL);
    }
  return 0;
}
// END CUT HERE
