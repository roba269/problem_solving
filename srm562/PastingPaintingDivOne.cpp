/* SRM 562 Div 1 Lev 1 */
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

VS mp;
int ch2id[300];

class PastingPaintingDivOne {
public:
  void put(const VS &bd, int d) {
    for (int i = 0 ; i < bd.size() ; ++i)
      for (int j = 0 ; j < bd[0].size() ; ++j)
        if (i + d < mp.size() && j + d < mp[0].size() && bd[i][j] != '.') mp[i+d][j+d] = bd[i][j];
  } 
  vector<LL> count(VS mp) {
    vector<LL> res;
    res.PB(0);
    res.PB(0);
    res.PB(0);
    for (int i = 0 ; i < mp.size(); ++i)
      for (int j = 0 ;j < mp[0].size(); ++j)
      if (mp[i][j] != '.') ++res[ch2id[mp[i][j]]];
    return res;
  }
  char combine(char ch, char next) {
    if (next == '.') return ch;
    return next;
  }
  void output(VS mp) {
    for (int i = 0 ;i < mp.size() ; ++i)
      printf("%s\n", mp[i].c_str());
    printf("\n");
  }
  vector<long long> countColors(vector <string> bd, int T) {
    ch2id['R'] = 0;
    ch2id['G'] = 1;
    ch2id['B'] = 2;
    ch2id['.'] = 3;
    int H = bd.size(), W = bd[0].size();
    mp = bd;
    for (int i = 1 ; i < min(T, min(H, W)) ; ++i) {
      put(bd, i);
    }
    
    vector<long long> res = count(mp);
    LL cnt[4];
    CLEAR(cnt);
    for (int i = 0 ; i < H ; ++i) {
      for (int j = 0 ; j < W ; j++) {
        if (i == H-1 || j == W-1) ++cnt[ch2id[mp[i][j]]];
      }
    }
    for (int i = 0 ; i < 3 ; ++i) {
      if (T > min(H,W)) cnt[i] *= T - min(H,W);
      else cnt[i] = 0;
    }
    for (int i = 0 ; i < H ; ++i) {
      for (int j = 0 ; j < W ; ++j) {
        if (i == H-1 || j == W-1) {
          for (int iter = 1 ; iter < min(T, min(H,W)) ; ++iter) {
            char v = '.';
            for (int tmp = 0 ; tmp < iter ; ++tmp) {
              if (i < tmp || j < tmp) break;
              // printf("i:%d j:%d tmp:%d iter:%d\n",i,j,tmp,iter);
              v = combine(v, bd[i-tmp][j-tmp]);
            }
            // printf("%c\n",v);
            ++cnt[ch2id[v]];
          }
        }
      }
    }
    for (int i = 0 ; i < 3 ; i++) res[i] += cnt[i];
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
  printf("lllll");
    {
        string clipboardARRAY[] = {
           "..G",
           "R..",
           "BG."
           };
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {3LL, 4LL, 3LL };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(0, theObject.countColors(clipboard, 3),retrunValue);
    }
    printf("dlagl\n");
    {
        string clipboardARRAY[] = {
           "R...",
           "....",
           "....",
           "...R"
           };
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {4L, 0L, 0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(1, theObject.countColors(clipboard, 2),retrunValue);
    }
    {
        string clipboardARRAY[] = {"RGB"};
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {100000L, 100000L, 100000L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(2, theObject.countColors(clipboard, 100000),retrunValue);
    }
    {
        string clipboardARRAY[] = {"."};
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {0L, 0L, 0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(3, theObject.countColors(clipboard, 1000000000),retrunValue);
    }
    {
        string clipboardARRAY[] = {
           "RB.",
           ".G."
           }
           ;
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {100L, 1L, 100L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(4, theObject.countColors(clipboard, 100),retrunValue);
    }
    {
        string clipboardARRAY[] = {
           "..........G..........",
           ".........G.G.........",
           "........G...G........",
           ".......G.....G.......",
           "......G..B.B..G......",
           ".....G...B.B...G.....",
           "....G...........G....",
           "...G...R.....R...G...",
           "..G.....RRRRRR....G..",
           ".G..........RR.....G.",
           "GGGGGGGGGGGGGGGGGGGGG"
           };
        vector <string> clipboard( clipboardARRAY, clipboardARRAY+ARRSIZE(clipboardARRAY) );
        long long retrunValueARRAY[] = {2000000018LL, 17000000048LL, 2000000005LL };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PastingPaintingDivOne theObject;
        eq(5, theObject.countColors(clipboard, 1000000000),retrunValue);
    }
    
  return 0;
}
// END CUT HERE
