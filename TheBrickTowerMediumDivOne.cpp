/* SRM 554 Div 1 Lev 2 AC */
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
int tk[51];

class TheBrickTowerMediumDivOne {
public:
  int n;
  int calc(VI &h) {
    int tot = 0;
    for (int i = 0 ; i < h.size() - 1 ; i++)
      tot += max(h[i], h[i+1]);
    return tot;
  }
  vector <int> find(vector <int> h) {
    n = h.size();
    VI tmp = h;
    sort(tmp.begin(), tmp.end());
    int best = calc(tmp);
    VI ans, s;
    CLEAR(tk);
    for (int i = 0 ; i < n ; ++i) {
      for (int id = 0 ; id < n ; ++id) {
        if (tk[id]) continue;
        tk[id] = 1;
        ans.push_back(id);
        s.push_back(h[id]);
        int cnt = 0;
        for (int k = 0 ; k < n ; ++k) {
          if (tk[k] == 0) {s.push_back(h[k]); ++cnt;}
        }
        sort(&s[i+1], &s[n]);
        /*printf("cnt:%d\n",cnt);
        for (int k = 0 ; k < s.size() ; ++k)
          printf("[%d]", s[k]);
        printf(" calc:%d\n", calc(s));*/
        if (calc(s) == best) {
          while (cnt--) s.pop_back();
          break;
        }
        tk[id] = 0;
        while (cnt--) s.pop_back();
        ans.pop_back();
        s.pop_back();
        // printf("s.size():%d\n",s.size());
      }
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
        int heightsARRAY[] = {4, 7, 5};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(0, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {4, 4, 4, 4, 4, 4, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 3, 4, 5, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(1, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {2, 3, 3, 2};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 3, 1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(2, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {13, 32, 38, 25, 43, 47, 6};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 6, 3, 1, 2, 4, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(3, theObject.find(heights),retrunValue);
    }
  return 0;
}
// END CUT HERE
