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
VI mp[MAXN];
int deg[MAXN];
int cnt_deg[MAXN];
int ub[MAXN], f[MAXN], dep[MAXN];
int lay_cnt[MAXN];

class HatRack {
public:
  int n;
  int dfs(int p, int fa, int lay) {
    ++lay_cnt[lay];
    VI ss;
    f[p] = fa;
    for (int i = 0 ; i < mp[p].size() ; ++i) {
      int id = mp[p][i];
      if (id == fa) continue;
      ss.push_back(dep[id] = dfs(id, p, lay+1));
      if (ub[id]) ub[p] = 1;
    }
    if (ss.empty()) return 0;
    if (ss.size() == 1) {
      ub[p] = 1;
      return ss[0] + 1;
    }
    assert(ss.size() == 2);
    if (ss[0] == ss[1]) {return 1 + ss[0];}
    ub[p] = 1;
    return 1 + max(ss[0], ss[1]);
  }
  long long calc() {
    LL s = 1;
    for (int i = 0 ; i < n ; i++) {
      int cnt_ub = 0, tot = 0;
      VI tt;
      for (int j = 0 ; j < mp[i].size() ; j++) {
        if (mp[i][j] == f[i]) continue;
        if (ub[mp[i][j]]) ++cnt_ub;
        ++tot;
        tt.PB(dep[mp[i][j]]);
      }
      // printf("i:%d cnt_ub:%d\n", i, cnt_ub);
      if (cnt_ub > 1) return 0;
      if (tot == 2 && abs(tt[0] - tt[1]) > 1) {
        // printf("dep[%d]:%d dep[%d]:%d\n", mp[i][0], dep[mp[i][0]], mp[i][1], dep[mp[i][1]]);
        return 0;
      }
      if (tot == 2 && cnt_ub == 1 && abs(tt[0] - tt[1]) > 1) return 0;
      if (tot == 2 && cnt_ub == 0 && tt[0] == tt[1]) s *= 2;
    }
    return s;
  }
  long long countWays(vector <int> k1, vector <int> k2) {
    if (k1.size() == 1) {
      return 2;
    }
    n = k1.size() + 1;
    for (int i = 0 ; i < n ; i++) mp[i].clear();
    CLEAR(deg);
    for (int i = 0 ; i < k1.size() ; ++i) {
      --k1[i]; --k2[i];
      mp[k1[i]].PB(k2[i]);
      mp[k2[i]].PB(k1[i]);
      ++deg[k1[i]];
      ++deg[k2[i]];
    }
    CLEAR(cnt_deg);
    for (int i = 0 ; i < n ; i++) {
      if (deg[i] > 3) return 0;
      ++cnt_deg[deg[i]];
    }
    if (cnt_deg[2] == 0 || cnt_deg[2] > 2) return 0;
    LL res = 0;
      for (int i = 0 ; i < n ; i++)
        if (deg[i] == 2) {
          CLEAR(ub);
          CLEAR(dep);
          CLEAR(lay_cnt);
          memset(f, -1, sizeof(f));
          dep[i] = dfs(i, -1, 0);
          int flg = 1;
          LL tmp = 1;
          for (int lay = 0 ; lay_cnt[lay] ; ++lay) {
            if (lay_cnt[lay] != tmp && lay_cnt[lay+1] != 0) {flg = 0; break;}
            tmp *= 2;
          }
          if (!flg) continue;
          // for (int k = 0 ;k < n ; ++k)
          //   printf("ub[%d]:%d dep:%d\n",k,ub[k],dep[k]);
          res += calc();
          // printf("%lld\n", res);
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
        int knob1ARRAY[] = {1};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {2};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(0, theObject.countWays(knob1, knob2),2LL);
    }
    {
        int knob1ARRAY[] = {1,1};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {2,3};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(1, theObject.countWays(knob1, knob2),2LL);
    }
    
    {
        int knob1ARRAY[] = {7, 5, 5, 7, 4, 5, 6, 2, 2};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] =  {3, 2, 3, 8, 1, 1, 1, 10, 9};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(50, theObject.countWays(knob1, knob2),0LL);
    }
  
    {
        int knob1ARRAY[] = {1,1,1,1};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {2,3,4,5};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(2, theObject.countWays(knob1, knob2),0LL);
    }
    
    {
        int knob1ARRAY[] = {6,6,6,4,1};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {1,2,4,5,3};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(3, theObject.countWays(knob1, knob2),0LL);
    }
  
    {
        int knob1ARRAY[] = {1,1,2,2,11,11,8,8,3,3,4,4,5};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {2,3,11,8,12,13,9,10,4,5,7,6,14};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(4, theObject.countWays(knob1, knob2),16LL);
    }
    
    {
        int knob1ARRAY[] = {1,2,3,4,5,6,7,8,9};
        vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
        int knob2ARRAY[] = {2,3,4,5,6,7,8,9,10};
        vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
        HatRack theObject;
        eq(5, theObject.countWays(knob1, knob2),0LL);
    }
      
  return 0;
}
// END CUT HERE
