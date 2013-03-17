/* SRM 561 div 1 lev 2 */
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

typedef long long LL;
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;
const int MAXN = 52;

#define SQR(x) ((x)*(x))
int od[MAXN], v[MAXN], fa[MAXN];
int subtree[MAXN][MAXN];

class CirclesGame {
public:
  int n;
  vector<int> mp[MAXN];
  int contain(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dis = SQR(x1-x2) + SQR(y1-y2);
    return dis < SQR(r1-r2); 
  }
  int brother(int p) {
    int s = 0;
    for (int i = 0 ; i < mp[fa[p]].size() ; ++i) {
      int id = mp[fa[p]][i];
      if (id == p) continue;
      assert(v[id] != -1);
      s ^= v[id];
    }
    return s;
  }
  int solve(int p) {
    for (int i = 0 ; i < mp[p].size() ; ++i) {
      solve(mp[p][i]);
    }
    set<int> tk;
    for (int i = 0 ; i < n ; i++) {
      if (i != p && !subtree[p][i]) continue;
      // we pick circle i, find the sg
      int s = 0;
      // all the son
      for (int j = 0 ; j < mp[i].size() ; ++j) {
        int id = mp[i][j];
        assert(v[id] != -1);
        s ^= v[id];
      }
      // all the brother
      int tmp = i;
      while (tmp != p) {
        s ^= brother(tmp);
        tmp = fa[tmp];
      }
      tk.insert(s);
    }
    for (int i = 0 ; ; ++i)
      if (!tk.count(i)) {v[p] = i; break;}
    return v[p];
  }
  string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
    n = x.size();
    for (int i = 0 ; i < n ; ++i) mp[i].clear();
    memset(od, 0, sizeof(od));
    memset(subtree, 0, sizeof(subtree));
    memset(fa, -1, sizeof(fa));
    memset(v, -1, sizeof(v));
    for (int i = 0 ; i < n ; i++) {
      int minr = INF, minj = -1;
      for (int j = 0 ; j < n ; j++) {
        if (r[j] <= r[i]) continue;
        if (j == i || !contain(x[j], y[j], r[j], x[i], y[i], r[i])) continue;
        if (r[j] < minr) {minr = r[j]; minj = j;}
      }
      if (minj != -1) {
        mp[minj].PB(i);
        ++od[i];
        fa[i] = minj;
      }
    }
    for (int i = 0 ; i < n ; ++i) {
      int tmp = i;
      while (fa[tmp] != -1) {
        tmp = fa[tmp];
        subtree[tmp][i] = 1;
      }
    }
    int sg = 0;
    for (int i = 0 ; i < n ; i++) {
      if (od[i] == 0) {
        sg ^= solve(i);
      }
    }
    if (sg == 0) return "Bob";
    return "Alice";
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
  /*
    {
        int xARRAY[] = {0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(0, theObject.whoCanWin(x, y, r),"Alice");
    }
    
    {
        int xARRAY[] = {0, 3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1, 1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(1, theObject.whoCanWin(x, y, r),"Bob");
    }
    {
        int xARRAY[] = {0, 0, 5};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0, 0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1, 2, 1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(2, theObject.whoCanWin(x, y, r),"Alice");
    }
    
    {
        int xARRAY[] = {0, 0, 0, 10, 10, 20};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0, 0, 0, 0, 0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1, 2, 3, 1, 2, 1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(3, theObject.whoCanWin(x, y, r),"Bob");
    }
    
    {
        int xARRAY[] = {10,20,30,40,50,60,70,80};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {8,7,6,5,4,3,2,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {2,2,2,2,2,2,2,2};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(4, theObject.whoCanWin(x, y, r),"Bob");
    }
    {
        int xARRAY[] = {0, 3, 6, 9, 12, -4747, -4777};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-5858, -5858, -5858, -5858, -5858, 777, 777};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {58, 1, 1, 1, 1, 44, 8};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(5, theObject.whoCanWin(x, y, r),"Bob");
    }
    {
        int xARRAY[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CirclesGame theObject;
        eq(6, theObject.whoCanWin(x, y, r),"Alice");
    }
    */
    {
      int x[] = {9659, -7125, -6257, 7872, 7570, -1172, 7375, 4158, -3041, 8005, 5481, -7277, 9519, -2155, -9347, 836, -7025, 0, 0, 0, 0};
      int y[] = {7657, -6899, -8435, 8657, -3989, 7797, -6908, -3003, 4674, -477, 3196, 6528, -7323, -8396, 8741, -9171, -6490, 0, 0, 0, 0}; 
      int r[] = {170, 9787, 4960, 4450, 22, 1571, 253, 394, 857, 2105, 210, 959, 1674, 364, 4452, 1150, 1063, 1, 2, 3, 4};
      vector<int> xv(x, x+sizeof(x)/x[0]);
      vector<int> yv(y, y+sizeof(y)/y[0]);
      vector<int> rv(r, r+sizeof(r)/r[0]);
      CirclesGame theObject;
      eq(7 , theObject.whoCanWin(xv, yv, rv),"Bob");
    }
    
    {
      int x[] = {-9571, -3067, -2261, 7428, 7182, -6876, 8574, 2170, -3035, -9546, -2128, 9544, -4637, 7870, 96, 5607, -3692, 9144, 2254, 3637, -4686, 9795, 6169, 9381, 6392, -4899, -2561, -7480, -3405, 8975, 2020, -5953, 8338, -4915, -8959, -9885, 8514, 1553, -6084, -8218, 2034};
      int y[] = {-3148, 9495, 2147, -8047, -6694, -3986, 7994, 2425, 7990, 5470, 9454, -2391, 9457, -1254, -2885, -5752, 6908, 6341, -7133, 2956, -464, 8927, -4266, -7356, 7302, -8178, -4092, 2705, -506, -9450, -9145, -5626, -4100, -1822, -1139, 28, -8128, -8080, 8388, 8120, 807};
      int r[] = {3449, 6093, 1151, 9342, 6809, 55, 4988, 890, 4050, 796, 2072, 271, 11, 611, 55, 2942, 109, 927, 421, 577, 48, 1604, 949, 8, 920, 2330, 1394, 67, 1113, 179, 318, 227, 209, 10, 1182, 19, 384, 638, 142, 482, 391};
      vector<int> xv(x, x+sizeof(x)/x[0]);
      vector<int> yv(y, y+sizeof(y)/y[0]);
      vector<int> rv(r, r+sizeof(r)/r[0]);
      CirclesGame theObject;
      eq(8, theObject.whoCanWin(xv, yv, rv),"Alice");
    }
    
  return 0;
}
// END CUT HERE
