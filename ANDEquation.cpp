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
using namespace std;

#define PB push_back
#define MP make_pair

typedef long long LL;
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;

class ANDEquation {
public:
  int restoreY(vector <int> a) {
		for (int i = 0 ; i < a.size() ; ++i) {
      int tmp = -1; 
      for (int j = 0 ; j < a.size() ; ++j) {
        if (j != i) {
          if (tmp == -1) tmp = a[j];
          else tmp &= a[j];
        }
      }
      if (tmp == a[i]) return a[i];
		}
    return -1;
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
        int AARRAY[] = {1, 3, 5}
           ;
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(0, theObject.restoreY(A),1);
    }
    {
        int AARRAY[] = {31, 7}
           ;
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(1, theObject.restoreY(A),-1);
    }
    {
        int AARRAY[] = {31, 7, 7}
           ;
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(2, theObject.restoreY(A),7);
    }
    {
        int AARRAY[] = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,
            0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(3, theObject.restoreY(A),0);
    }
    {
        int AARRAY[] = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
            191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
            191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
            191411,191411,191411};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(4, theObject.restoreY(A),191411);
    }
    {
        int AARRAY[] = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(5, theObject.restoreY(A),-1);
    }
    {
        int AARRAY[] = {2, 3, 7, 19};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        ANDEquation theObject;
        eq(6, theObject.restoreY(A),-1);
    }
  return 0;
}
// END CUT HERE
