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

LL b[22];

class SetAndSet {
public:
  int calc_dig(LL v) {
    int s = 0;
    while (v) {
      v &= (v - 1);
      ++s;
    }
    return s;
  }
  long long countandset(vector <int> A) {
    VI tmp = A;
    int n = A.size();
    CLEAR(b);
    for (int i = 0 ; i < 20 ; i++) {
      for (int j = 0 ; j < A.size() ; ++j) {
        if (tmp[j] & 1) b[i] |= (1LL << j);
        tmp[j] >>= 1; 
      }
    }
    int nb = 0;
    for (int i = 0 ; i < 20 ; i++) {
      if (b[i] == 0 || b[i] == (1LL << n) - 1) continue;
      b[nb++] = b[i];
    }
    // for (int i = 0 ; i < nb ; ++i)
    //   printf("b[%d]:%lld\n",i,b[i]);
    LL tot = 0;
    for (int mask = 0 ; mask < (1<<nb) ; ++mask) {
      LL tv = -1;
      for (int i = 0 ; i < n ; ++i) {
        if (mask&(1<<i)) tv &= b[i];
      }
      int cnt_dig = calc_dig(tv);
      int flg = (calc_dig(mask) % 2 != 0 ? 1 : -1);
      tot += flg * ((1LL << cnt_dig) - 1);
    }
    printf("tot:%lld\n",tot);
    LL ans = (1LL << n) - 2 - 2 * tot;
    // if (ans < 0) return 0;
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
        int AARRAY[] = {7,4,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SetAndSet theObject;
        eq(0, theObject.countandset(A),0LL);
    }
    {
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SetAndSet theObject;
        eq(1, theObject.countandset(A),2LL);
    }
    {
        int AARRAY[] = {1,2,3,4,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SetAndSet theObject;
        eq(2, theObject.countandset(A),8LL);
    }
    {
        int AARRAY[] = {6,6,6};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SetAndSet theObject;
        eq(3, theObject.countandset(A),6LL);
    }
    {
        int AARRAY[] = {13,10,4,15,4,8,4,2,4,14,0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SetAndSet theObject;
        eq(4, theObject.countandset(A),1728LL);
    }
  return 0;
}
// END CUT HERE
