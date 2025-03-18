/* SRM 560 Div1 Lev2 */
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

class MySet {
public:
  MySet() {
    stamp = 1;
    memset(a, 0, sizeof(a));
    len = 0;
  }
  void insert(PII item) {
    if (a[item.first+300][item.second+100] != stamp) {
      a[item.first+300][item.second+100] = stamp;
      mylist[len++] = item;
    }
  }
  int count(PII item) {
    return a[item.first+300][item.second+100] == stamp;
  }
  void clear() {
    ++stamp;
    len = 0;
  }
private:
  int a[620][620];
  int stamp;
public:
  PII mylist[620*620];
  int len;
};
 
MySet *sp = new MySet();
MySet *sp2 = new MySet();

class DrawingPointsDivOne {
public:
  VI x, y;
  int check(int k) {
    // expand
    sp->clear();
    for (int i = 0 ; i < x.size() ; ++i) {
      for (int tx = x[i] - k ; tx <= x[i] + k ; tx += 2) {
        for (int ty = y[i] - k ; ty <= y[i] + k ; ty += 2) {
          sp->insert(MP(tx,ty));
        }
      }
    }
    // reduce
    for (int iter = 0 ; iter < k ; ++iter) {
      sp2->clear();
      for (int i = 0 ; i < sp->len ; ++i) {
        PII item = sp->mylist[i];
        if (sp->count(MP(item.first, item.second)) &&
          sp->count(MP(item.first+2, item.second)) &&
          sp->count(MP(item.first, item.second+2)) &&
          sp->count(MP(item.first+2, item.second+2))) {
            sp2->insert(MP(item.first+1, item.second+1));
          }
      }
      swap(sp, sp2);
    }
    if (sp->len != x.size()) return 0;
    for (int i = 0 ; i < x.size() ; ++i)
      if (sp->count(MP(x[i], y[i])) == 0) return 0;
    return 1;
  }
  int maxSteps(vector <int> _x, vector <int> _y) {
    if (_x.size() == 1) return -1;
    x = _x; y = _y;
    for (int i = 0 ; i < x.size() ; ++i) x[i] *= 2;
    for (int i = 0 ; i < y.size() ; ++i) y[i] *= 2;
    int lo = 0, hi = 150;
    int ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      // printf("mid:%d lo:%d hi:%d\n",mid,lo,hi);
      if (check(mid)) {
        if (mid > ans) ans = mid;
        lo = mid + 1;
      } else hi = mid - 1;
    }
    if (ans >= 150) return -1;
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
        int xARRAY[] = {0, 3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        DrawingPointsDivOne theObject;
        eq(0, theObject.maxSteps(x, y),1);
    }
    {
        int xARRAY[] = {0,2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        DrawingPointsDivOne theObject;
        eq(1, theObject.maxSteps(x, y),0);
    }
    {
        int xARRAY[] = {-70};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        DrawingPointsDivOne theObject;
        eq(2, theObject.maxSteps(x, y),-1);
    }
    {
        int xARRAY[] = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
            -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
            -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        DrawingPointsDivOne theObject;
        eq(3, theObject.maxSteps(x, y),9);
    }
  return 0;
}
// END CUT HERE
