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

class TomekPhone {
public:
  int minKeystrokes(vector <int> a, vector <int> cap) {
    int res = 0;
    int x[64];
    sort(a.begin(), a.end(), greater<int>());
    memset(x, 0, sizeof(x));
    for (int i = 1 ; i <= 50 ; ++i) {
      for (int j = 0 ; j < cap.size() ; ++j) {
        if (cap[j] >= i) ++x[i];
      }
    }
    
    int p = 1;
    for (int i = 0 ; i < a.size() ; ) {
      if (x[p]) {res += p * a[i]; --x[p]; ++i;}
      else {
        if (++p > 50) break;
      }
    }
    if (p > 50) return -1;
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
        int occurencesARRAY[] = {7,3,4,1};
        vector <int> occurences( occurencesARRAY, occurencesARRAY+ARRSIZE(occurencesARRAY) );
        int keySizesARRAY[] = {2,2};
        vector <int> keySizes( keySizesARRAY, keySizesARRAY+ARRSIZE(keySizesARRAY) );
        TomekPhone theObject;
        eq(0, theObject.minKeystrokes(occurences, keySizes),19);
    }
    {
        int occurencesARRAY[] = {13,7,4,20};
        vector <int> occurences( occurencesARRAY, occurencesARRAY+ARRSIZE(occurencesARRAY) );
        int keySizesARRAY[] = {2,1};
        vector <int> keySizes( keySizesARRAY, keySizesARRAY+ARRSIZE(keySizesARRAY) );
        TomekPhone theObject;
        eq(1, theObject.minKeystrokes(occurences, keySizes),-1);
    }
    {
        int occurencesARRAY[] = {11,23,4,50,1000,7,18};
        vector <int> occurences( occurencesARRAY, occurencesARRAY+ARRSIZE(occurencesARRAY) );
        int keySizesARRAY[] = {3,1,4};
        vector <int> keySizes( keySizesARRAY, keySizesARRAY+ARRSIZE(keySizesARRAY) );
        TomekPhone theObject;
        eq(2, theObject.minKeystrokes(occurences, keySizes),1164);
    }
    {
        int occurencesARRAY[] = {100,1000,1,10};
        vector <int> occurences( occurencesARRAY, occurencesARRAY+ARRSIZE(occurencesARRAY) );
        int keySizesARRAY[] = {50};
        vector <int> keySizes( keySizesARRAY, keySizesARRAY+ARRSIZE(keySizesARRAY) );
        TomekPhone theObject;
        eq(3, theObject.minKeystrokes(occurences, keySizes),1234);
    }
    {
        int occurencesARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
        vector <int> occurences( occurencesARRAY, occurencesARRAY+ARRSIZE(occurencesARRAY) );
        int keySizesARRAY[] = {10,10,10,10,10,10,10,10};
        vector <int> keySizes( keySizesARRAY, keySizesARRAY+ARRSIZE(keySizesARRAY) );
        TomekPhone theObject;
        eq(4, theObject.minKeystrokes(occurences, keySizes),3353);
    }
  return 0;
}
// END CUT HERE
