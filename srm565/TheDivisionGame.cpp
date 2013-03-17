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

int a[1000100], mul[1000100];
int plist[1000100], pl;
int prime[1000100];

class TheDivisionGame {
public:
  void init_prime() {
    memset(prime, 0, sizeof(prime));
    for (int i = 2 ; i < 1000100 ; ++i)
      if (!prime[i])
        for (LL j = (LL)i * i ; j < 1000100 ; j += i) {
          prime[j] = 1;
        }
    pl = 0;
    for (int i = 2 ; i < 1000100 ; ++i)
      if (prime[i] == 0) plist[pl++] = i;
  }
  long long countWinningIntervals(int L, int R) {
    init_prime();
    memset(a, 0, sizeof(a));
    for (int i = 0 ; i <= R - L ; ++i)
      mul[i] = 1;
    for (int i = 0 ; i < pl ; ++i) {
      LL p = plist[i];
      while (p <= R) {
        for (LL st = (LL)L / p * p ; st <= R ; st += p) {
          if (st < L) continue;
          ++a[st-L];
          mul[st-L] *= plist[i];
        }
        p *= plist[i];
      }
    }
    for (int i = L ; i <= R ; ++i)
      if (mul[i-L] != i) {
        for (int j = i ; j <= R ; j += i)
          ++a[j-L];
      }
    map<int,int> cnt;
    LL res = (LL)(R - L + 2) * (R - L + 1) / 2;
    int val = 0;
    cnt[0] = 1;
    for (int i = 0 ; i <= R - L ; ++i) {
      val ^= a[i];
      res -= cnt[val];
      cnt[val]++;
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
        TheDivisionGame theObject;
        eq(0, theObject.countWinningIntervals(9, 10),2LL);
    }
    {
        TheDivisionGame theObject;
        eq(1, theObject.countWinningIntervals(2, 5),9LL);
    }
    {
        TheDivisionGame theObject;
        eq(2, theObject.countWinningIntervals(2, 6),13LL);
    }
    {
        TheDivisionGame theObject;
        eq(3, theObject.countWinningIntervals(2, 100),4345LL);
    }
    {
        TheDivisionGame theObject;
        eq(4, theObject.countWinningIntervals(12566125, 12567777),1313432LL);
    }
  return 0;
}
// END CUT HERE
