/* SRM 561 Dev 2 Lev 3 */
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
const int MAXN = 55;

class FoxAndTouristFamilies {
public:
  int n;
  VI mp[MAXN];
  void get_nodes(int root, int fa, set<int> &res) {
    res.insert(root);
    for (int i = 0 ; i < mp[root].size() ; ++i) {
      int id = mp[root][i];
      if (fa == id) continue;
      get_nodes(id, root, res);
    }
  }
  double expectedLength(vector <int> A, vector <int> B, vector <int> f) {
    n = A.size() + 1;
    for (int i = 0 ; i < n ; i++) mp[i].clear();
    for (int i = 0 ; i < A.size() ; ++i) {
      mp[A[i]].PB(B[i]);
      mp[B[i]].PB(A[i]);
    }
    double ans = .0;
    for (int i = 0 ; i < A.size() ; ++i) {
      set<int> s1, s2;
      get_nodes(A[i], B[i], s1);
      get_nodes(B[i], A[i], s2);
      int c1 = 0, c2 = 0;
      for (int j = 0 ; j < f.size() ; ++j) {
        if (s1.count(f[j])) ++c1;
        else if (s2.count(f[j])) ++c2;
      }
      double v = pow((double)s2.size() / (n-1), c1) * pow((double)s1.size() / (n-1), c2);
      ans += v;
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
        int AARRAY[] = {0, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(0, theObject.expectedLength(A, B, f),1.5);
    }
    {
        int AARRAY[] = {0, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0, 0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(1, theObject.expectedLength(A, B, f),1.25);
    }
    {
        int AARRAY[] = {0, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0, 1};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(2, theObject.expectedLength(A, B, f),0.75);
    }
    {
        int AARRAY[] = {0, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0, 2};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(3, theObject.expectedLength(A, B, f),1.0);
    }
    {
        int AARRAY[] = {0,0,0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(4, theObject.expectedLength(A, B, f),1.0);
    }
    {
        int AARRAY[] = {0,0,0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {1,2};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(5, theObject.expectedLength(A, B, f),0.7777777777777777);
    }
    {
        int AARRAY[] = {0,1,1,3,5,6};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,4,4,4};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {5,6,1};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(6, theObject.expectedLength(A, B, f),0.4537037037037037);
    }
    {
        int AARRAY[] = {0,1,2,3,4,5,6,7,8,9};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int fARRAY[] = {0,0,0,0,0,0,0,0,0,0};
        vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
        FoxAndTouristFamilies theObject;
        eq(7, theObject.expectedLength(A, B, f),1.4914341925000003);
    }
  return 0;
}
// END CUT HERE
