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
typedef vector<int> VI;
const int INF = 1000100100;
const int MOD = 1000000007;
const LL LLINF = (LL)INF * INF;

class DefectiveAddition {
public:
  int count(vector <int> cards, int k) {
    int res = 0;
    sort(cards.begin(), cards.end());
    
    LL t = 1;
    int n = cards.size();
    int tmp = cards[n-1];
    if (tmp == 0) return k == 0;
    while (tmp) {
      tmp >>= 1;
      t <<= 1;
    }
    if (k >= t) return 0;
    t >>= 1;
    
    // not set most sig bit
    LL cnt[52][2];
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    for (int i = 0 ; i < n-1 ; ++i) {
      for (int j = 0 ; j < 2 ; ++j) {
        cnt[i][j] %= MOD;
        if (cards[i] < t) {
          cnt[i+1][j] += (cnt[i][j] * (cards[i]+1)) % MOD;
        } else {
          cnt[i+1][j] += (cnt[i][j] * t) % MOD;
          cnt[i+1][j^1] += cnt[i][j] * (cards[i]-t+1) % MOD;
        }
      }
    }
    if (k < t) res += cnt[n-1][0];
    else res += cnt[n-1][1];
    res %= MOD;
    
    // set most sig bit
    VI tc(cards);
    tc[n-1] -= t;
    res += count(tc, k^t);
    res %= MOD;
    
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
      int cardsARRAY[] = {1};
      vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
      DefectiveAddition theObject;
      eq(0, theObject.count(cards, 1),1);
  }
    {
        int cardsARRAY[] = {2,3};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(0, theObject.count(cards, 2),3);
    }
    {
        int cardsARRAY[] = {1,2,3};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(1, theObject.count(cards, 1),6);
    }
    {
        int cardsARRAY[] = {4, 5, 7, 11};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(2, theObject.count(cards, 6),240);
    }
    {
        int cardsARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(3, theObject.count(cards, 15),1965600);
    }
    {
        int cardsARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(4, theObject.count(cards, 16),0);
    }
    {
        int cardsARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> cards( cardsARRAY, cardsARRAY+ARRSIZE(cardsARRAY) );
        DefectiveAddition theObject;
        eq(5, theObject.count(cards, 1),949480669);
    }
  return 0;
}
// END CUT HERE
