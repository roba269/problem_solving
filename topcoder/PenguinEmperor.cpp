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
const int MOD = 1000000007;
const LL LLINF = (LL)INF * INF;
const int MAXN = 352;

struct Matrix {int r,c,s[MAXN][MAXN];};

void matrix_multiple(Matrix *a,Matrix *b,Matrix *c)
{
    int i,j,k;
    memset(c,0,sizeof(Matrix));
    if (a->c != b->r) return;
    c->r = a->r; c->c = b->c;
    for (i = 0 ; i < a->r ; i++)
        for (j = 0 ; j < b->c ; j++)
            for (k = 0 ; k < a->c ; k++) {
                c->s[i][j] += (int)(((LL)a->s[i][k] * b->s[k][j]) % MOD);
                c->s[i][j] %= MOD;
              }
}

Matrix ans, tmp, s;

Matrix matrix_power(Matrix *a,LL p)
{
    s = *a;
    // printf("fuck\n");
    // return s;
    memset(&ans,0,sizeof(ans));
    while (p) {
      printf("%lld\n",p);
        if (p & 1) {
            if (ans.r == 0) ans = s;
            else {matrix_multiple(&ans,&s,&tmp); ans = tmp;}
        }
        matrix_multiple(&s,&s,&tmp); s = tmp; p >>= 1;   
    } 
    return ans;
}

Matrix tmp2, mm;

void output(Matrix *m) {
  printf("==\n");
  for (int i = 0 ; i < m->r ; i++) {
    for (int j = 0 ; j < m->c ; ++j)
      printf(" %d", m->s[i][j]);
    printf("\n");
  }
}
class PenguinEmperor {
public:
  int countJourneys(int n, long long day) {
    memset(&tmp, 0, sizeof(tmp));
    memset(&mm, 0, sizeof(mm));
    mm.r = mm.c = n;
    tmp.r = tmp.c = n;
    tmp2.r = tmp2.c = n;
    printf("??\n");
    for (int i = 1 ; i <= n ; ++i) {
      for (int row = 0 ; row < n ; ++row) {
        tmp.s[row][(row+i)%n] = 1;
        tmp.s[row][(row-i+n)%n] = 1;
      }
      if (i == 1) mm = tmp;
      else {
        // printf("dlaslg\n");
        // return 0;
        matrix_multiple(&mm, &tmp, &tmp2);
        
        mm = tmp2;
      }
      memset(&tmp, 0, sizeof(tmp));
      tmp.r = tmp.c = n;
    }
    // return 0;
    if (day >= n) {
      mm = matrix_power(&mm, day / n);
    } else {
      memset(&mm, 0, sizeof(mm));
      mm.r = mm.c = n;
      for (int i = 0 ; i < n ; i++)
        mm.s[i][i] = 1;
    }
    // output(&mm);
    LL left = day % n;
    for (int i = 1 ; i <= left ; ++i) {
      memset(&tmp, 0, sizeof(tmp));
      tmp.r = tmp.c = n;
      for (int row = 0 ; row < n ; ++row) {
        tmp.s[row][(row+i)%n] = 1;
        tmp.s[row][(row-i+n)%n] = 1;
      }
      // printf("tmp:\n");
      // output(&tmp);
      matrix_multiple(&mm, &tmp, &tmp2);
      mm = tmp2;
    }
    return mm.s[0][0];
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
        PenguinEmperor theObject;
        eq(0, theObject.countJourneys(3, 2LL),2);
    }
    {
        PenguinEmperor theObject;
        eq(1, theObject.countJourneys(4, 3LL),2);
    }
    
    {
        PenguinEmperor theObject;
        eq(2, theObject.countJourneys(5, 36LL),107374182);
    }
    {
        PenguinEmperor theObject;
        eq(3, theObject.countJourneys(300, 751LL),413521250);
    }
    {
        PenguinEmperor theObject;
        eq(4, theObject.countJourneys(300, 750LL),0);
    }
    {
        PenguinEmperor theObject;
        eq(5, theObject.countJourneys(350, 1000000000000000000LL),667009739);
    }
    {
        PenguinEmperor theObject;
        eq(6, theObject.countJourneys(5, 7LL),12);
    }
    
  return 0;
}
// END CUT HERE
