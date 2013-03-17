/* SRM 552 Div1 Lev2 AC */
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

int sum[2][35][35];

class FoxAndFlowerShopDivOne {
public:
  int R, C;
  map<int,int> xx1[32], xx2[32], yy1[32], yy2[32];
  inline int calc(int x1, int y1, int x2, int y2, int c) {
    return sum[c][x2][y2] - sum[c][x1-1][y2] - sum[c][x2][y1-1] + sum[c][x1-1][y1-1];
  }
  int theMaxFlowers(vector <string> f, int m) {
    R = f.size();
    C = f[0].size();
    CLEAR(sum);
    for (int i = 1 ; i <= R ; ++i) {
      for (int j = 1 ; j <= C ; ++j) {
        for (int tx = 1 ; tx <= i ; ++tx)
          for (int ty = 1 ; ty <= j ; ++ty) {
            sum[0][i][j] += (f[tx-1][ty-1] == 'L');
            sum[1][i][j] += (f[tx-1][ty-1] == 'P');
          }
      }
    }
    for (int i = 1 ; i <= R ; ++i)
      for (int j = 1 ; j <= C ; ++j)
      for (int i2 = i ; i2 <= R ; ++i2)
      for (int j2 = j ; j2 <= C ; ++j2) {
        // int S = (i2-i+1) * (j2-j+1);
        int S = calc(i,j,i2,j2,0) + calc(i,j,i2,j2,1);
        int v = calc(i,j,i2,j2,0) - calc(i,j,i2,j2,1);
        if (xx1[i2].count(v) == 0) {
          xx1[i2][v] = S;
        } else if (S > xx1[i2][v]) xx1[i2][v] = S;
        if (xx2[i].count(v) == 0) {
          xx2[i][v] = S;
        } else if (S > xx2[i][v]) xx2[i][v] = S;
        if (yy1[j2].count(v) == 0) {
          yy1[j2][v] = S;
        } else if (S > yy1[j2][v]) yy1[j2][v] = S;
        if (yy2[j].count(v) == 0) {
          yy2[j][v] = S;
        } else if (S > yy2[j][v]) yy2[j][v] = S;
      }
    for (int i = 2 ; i <= R ; ++i) {
      map<int,int>::iterator itr;
      for (itr = xx1[i-1].begin() ; itr != xx1[i-1].end() ; ++itr) {
        if (itr->second > xx1[i][itr->first])
          xx1[i][itr->first] = itr->second;
      }
    }
    for (int i = R - 1 ; i >= 1 ; --i) {
      map<int,int>::iterator itr;
      for (itr = xx2[i+1].begin() ; itr != xx2[i+1].end() ; ++itr) {
        if (itr->second > xx2[i][itr->first])
          xx2[i][itr->first] = itr->second;
      }
    }
    for (int i = 2 ; i <= C ; ++i) {
      map<int,int>::iterator itr;
      for (itr = yy1[i-1].begin() ; itr != yy1[i-1].end() ; ++itr) {
        if (itr->second > yy1[i][itr->first])
          yy1[i][itr->first] = itr->second;
      }
    }
    for (int i = C - 1 ; i >= 1 ; --i) {
      map<int,int>::iterator itr;
      for (itr = yy2[i+1].begin() ; itr != yy2[i+1].end() ; ++itr) {
        if (itr->second > yy2[i][itr->first])
          yy2[i][itr->first] = itr->second;
      }
    }
    int best = -1;
    for (int splitx = 1 ; splitx + 1 <= R ; splitx++) {
      map<int,int>::iterator itr;
      for (itr = xx1[splitx].begin() ; itr != xx1[splitx].end() ; ++itr) {
        int v1 = itr->first;
        // abs(v1+v2) <= maxdiff
        // -m <= v1+v2 <= m
        // v2 >= -m-v1, v2 <= m-v1
        int up = min(2*R*C, m-v1);
        for (int v2 = max(-2*R*C, -m-v1) ; v2 <= up ; ++v2) {
          if (xx2[splitx+1].count(v2)) {
            int tmp = xx2[splitx+1][v2] + itr->second;
            if (tmp > best) best = tmp;
          }
        }
      }
    }
    for (int splity = 1 ; splity + 1 <= C ; ++splity) {
      map<int,int>::iterator itr;
      for (itr = yy1[splity].begin() ; itr != yy1[splity].end() ; ++itr) {
        int v1 = itr->first;
        // abs(v1+v2) <= maxdiff
        // -m <= v1+v2 <= m
        // v2 >= -m-v1, v2 <= m-v1
        int up = min(2*R*C, m-v1);
        for (int v2 = max(-2*R*C, -m-v1) ; v2 <= up ; ++v2) {
          if (yy2[splity+1].count(v2)) {
            int tmp = yy2[splity+1][v2] + itr->second;
            if (tmp > best) best = tmp;
          }
        }
      }
    }
    return best;
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
        string flowersARRAY[] = {"LLLP..LLP.PLL.LL..LP",
            "L.PL.L.LLLL.LPLLPLP.",
            "PLL.LL.LLL..PL...L..",
            ".LPPP.PPPLLLLPLP..PP",
            "LP.P.PPL.L...P.L.LLL",
            "L..LPLPP.PP...PPPL..",
            "PP.PLLL.LL...LP..LP.",
            "PL...P.PPPL..PLP.L..",
            "P.PPPLPLP.LL.L.LLLPL",
            "PLLPLLP.LLL.P..P.LPL",
            "..LLLPLPPPLP.P.LP.LL",
            "..LP..L..LLPPP.LL.LP",
            "LPLL.PLLPPLP...LL..P",
            "LL.....PLL.PLL.P....",
            "LLL...LPPPPL.PL...PP",
            ".PLPLLLLP.LPP...L...",
            "LL...L.LL.LLLPLPPPP.",
            "PLPLLLL..LP.LLPLLLL.",
            "PP.PLL..L..LLLPPL..P",
            ".LLPL.P.PP.P.L.PLPLL"};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(5, theObject.theMaxFlowers(flowers, 9),208);
    }
    {
        string flowersARRAY[] = {"LLL",
            "PPP",
            "LLL"};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(0, theObject.theMaxFlowers(flowers, 1),7);
    }
    {
        string flowersARRAY[] = {"LLL",
            "PPP",
            "LLL"};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(1, theObject.theMaxFlowers(flowers, 0),6);
    }
    {
        string flowersARRAY[] = {"...",
            "...",
            "..."};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(2, theObject.theMaxFlowers(flowers, 3),0);
    }
    {
        string flowersARRAY[] = {"LLPL.LPP",
            "PLPPPPLL",
            "L.P.PLLL",
            "LPL.PP.L",
            ".LLL.P.L",
            "PPLP..PL"};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(3, theObject.theMaxFlowers(flowers, 2),38);
    }
    {
        string flowersARRAY[] = {"LLLLLLLLLL",
            "LLLLLLLLLL",
            "LLLLLLLLLL",
            "LLLLLLLLLL",
            "LLLLLLLLLL"};
        vector <string> flowers( flowersARRAY, flowersARRAY+ARRSIZE(flowersARRAY) );
        FoxAndFlowerShopDivOne theObject;
        eq(4, theObject.theMaxFlowers(flowers, 0),-1);
    }
   
  return 0;
}
// END CUT HERE
