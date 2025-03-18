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

class Incubator {
public:
  int n;
  int mp[MAXN][MAXN];
  int left[MAXN], cover[MAXN];
  int dfs(int p) {
    if (p == -1) return 1;
    for (int i = 0 ; i < n ; i++) {
      if (mp[p][i] && cover[i] == 0) {
        int tmp = left[i];
        left[i] = p;
        cover[i] = 1;
        if (dfs(tmp)) return 1;
        left[i] = tmp;
      }
    }
    return 0;
  }
  int match() {
    memset(left, -1, sizeof(left));
    int s = 0;
    for (int i = 0 ; i < n ; ++i) {
      memset(cover, 0, sizeof(cover));
      if (dfs(i)) ++s;
    }
    return s;
  }
  int maxMagicalGirls(vector <string> love) {
    CLEAR(mp);
    n = love.size();
    for (int i = 0 ; i < n ; i++)
      for (int j = 0 ; j < n ; j++)
        mp[i][j] = (love[i][j] == 'Y');
    for (int k = 0 ; k < n ; ++k)
      for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
          mp[i][j] |= mp[i][k] & mp[k][j];
    return n - match();
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
        string loveARRAY[] = {"NY","NN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(0, theObject.maxMagicalGirls(love),1);
    }
    {
        string loveARRAY[] = {"NYN", "NNY", "NNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(1, theObject.maxMagicalGirls(love),1);
    }
    {
        string loveARRAY[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(2, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(3, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(4, theObject.maxMagicalGirls(love),5);
    }
    {
        string loveARRAY[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(5, theObject.maxMagicalGirls(love),2);
    }
    {
        string loveARRAY[] = {"Y"};
        vector <string> love( loveARRAY, loveARRAY+ARRSIZE(loveARRAY) );
        Incubator theObject;
        eq(6, theObject.maxMagicalGirls(love),0);
    }
  return 0;
}
// END CUT HERE
