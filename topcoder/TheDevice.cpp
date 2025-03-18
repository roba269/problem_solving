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

class TheDevice {
public:
  int minimumAdditional(vector <string> p) {
    int ans = 0;
    for (int i = 0 ; i < p[0].size() ; ++i) {
      int c[2];
      c[0] = c[1] = 0;
      for (int j = 0 ; j < p.size() ; ++j) {
        ++c[p[j][i]-'0'];
      }
      int tmp = 0;
      if (c[0] < 1) tmp += 1 - c[0];
      if (c[1] < 2) tmp += 2 - c[1];
      if (tmp > ans) ans = tmp;
    }
    return ans;
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
        string platesARRAY[] = {"010",
            "011",
            "101"};
        vector <string> plates( platesARRAY, platesARRAY+ARRSIZE(platesARRAY) );
        TheDevice theObject;
        eq(0, theObject.minimumAdditional(plates),1);
    }
    {
        string platesARRAY[] = {"0",
            "1",
            "0",
            "1"};
        vector <string> plates( platesARRAY, platesARRAY+ARRSIZE(platesARRAY) );
        TheDevice theObject;
        eq(1, theObject.minimumAdditional(plates),0);
    }
    {
        string platesARRAY[] = {"01010101",
            "10101010"};
        vector <string> plates( platesARRAY, platesARRAY+ARRSIZE(platesARRAY) );
        TheDevice theObject;
        eq(2, theObject.minimumAdditional(plates),1);
    }
    {
        string platesARRAY[] = {"10010101011",
            "00010101001",
            "00100010111",
            "00101010101",
            "01010111101"};
        vector <string> plates( platesARRAY, platesARRAY+ARRSIZE(platesARRAY) );
        TheDevice theObject;
        eq(3, theObject.minimumAdditional(plates),1);
    }
    {
        string platesARRAY[] = {"1101001011010",
            "0010000010101",
            "1010101011110",
            "1101010100111",
            "1011111110111"};
        vector <string> plates( platesARRAY, platesARRAY+ARRSIZE(platesARRAY) );
        TheDevice theObject;
        eq(4, theObject.minimumAdditional(plates),0);
    }
  return 0;
}
// END CUT HERE
