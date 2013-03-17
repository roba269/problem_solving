/* SRM 558 Div 1 Lev 2 */
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

const double EPS = 1e-8;
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;
int cnt_array[10010];

class Ear {
public:
  VI vr, vbx, vby;
  int onleft(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1 >= 0;
  }
  inline int count(int x1, int x2) {
    if (x1 > x2 || x2 < 0 || x1 > 10000) return 0;
    if (x2 > 10000) x2 = 10000;
    if (x1 <= 0) return cnt_array[x2];
    else return cnt_array[x2] - cnt_array[x1-1];
  }
  inline void calc_cutx(int x1, int y1, int x2, int y2, int &lcut, int &rcut) {
    if (x1 == x2) {
      lcut = x1;
      rcut = x1 + 1;
      return;
    }
    LL tmp = -(LL)x1 * y2 + (LL)x2 * y1;
    if (tmp % (y1 - y2) == 0) {
      lcut = tmp / (y1 - y2);
      rcut = tmp / (y1 - y2) + 1;
    } else {
      double tx = (double)tmp / (y1 - y2);
      lcut = int(floor(tx)+EPS);
      rcut = int(ceil(tx)+EPS);
    }
  }
  long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
    string str;
    for (int i = 0 ; i < redX.size() ; ++i) str += redX[i];
    vr = splitInt(str);
    str = "";
    for (int i = 0 ; i < blueX.size() ; ++i) str += blueX[i];
    vbx = splitInt(str);
    str = "";
    for (int i = 0 ; i < blueY.size() ; ++i) str += blueY[i];
    vby = splitInt(str);
    
    CLEAR(cnt_array);
    for (int i = 0 ; i < vr.size() ; ++i)
      ++cnt_array[vr[i]];
    for (int i = 1 ; i <= 10000 ; ++i)
      cnt_array[i] += cnt_array[i-1];
    LL res = 0;
    for (int i = 0 ; i < vr.size() ; ++i) {
      for (int j = 0 ; j < vbx.size() ; ++j) {
        for (int k = 0 ; k < vbx.size() ; ++k) {
          if (j == k) continue;
          if (vbx[j] <= vr[i] || vbx[k] <= vr[i]) continue;
          if (vby[j] <= vby[k]) continue;
          int x1 = vbx[j] - vr[i], y1 = vby[j];
          int x2 = vbx[k] - vr[i], y2 = vby[k]; 
          if (onleft(x1, y1, x2, y2)) continue;
          
          // printf("A:{%d,0} {%d,%d} {%d,%d}\n", vr[i], vbx[j], vby[j], vbx[k], vby[k]);
          int lcut, rcut;
          calc_cutx(vbx[j], vby[j], vbx[k], vby[k], lcut, rcut);
          // printf(" lcut:%d rcut:%d\n",lcut,rcut);
          int cnt_b = count(vr[i]+1, vbx[k]-1);
          if (vbx[j] <= vbx[k]) {
            // int cutx_int = floor(cutx+EPS);
            // if (fabs(cutx_int - cutx) < EPS) --cutx_int;
            // case 1
            int c1 = count(vbx[k]+1, lcut);
            int c2 = count(rcut, 10000);
            // printf("_cntb:%d c1:%d c2:%d\n",cnt_b,c1,c2);
            res += (LL)cnt_b * c1 * c2;
            // case 2
            if (c2 > 0) res += (LL)cnt_b * c2 * (c2-1) / 2;
          } else {
            // case 1: C between Px and Qx
            int c1 = count(vbx[k]+1, vbx[j]);
            int c2 = count(vbx[j]+1, 10000);
            // printf("__cntb:%d c1:%d c2:%d\n",cnt_b,c1,c2);
            res += (LL)cnt_b * c1 * c2;
            // case 2: C > Px
            if (c2 > 0) res += (LL)cnt_b * c2 * (c2-1) / 2;
          }
          // printf("res:%lld\n", res);
        }
      }
    }
    return res;
  }
};

// BEGIN CUT HERE



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
        string redXARRAY[] = {"3 2 8 7"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"5 4"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"2 4"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(0, theObject.getCount(redX, blueX, blueY),1LL);
    }
    
    {
        string redXARRAY[] = {"3 2 8 7"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"2 8"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"3 4"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(1, theObject.getCount(redX, blueX, blueY),0LL);
    }
    
    {
        string redXARRAY[] = {"1 2 6 9"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"3 6 8 5"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"1 5 4 3"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(2, theObject.getCount(redX, blueX, blueY),4LL);
    }
  
    {
        string redXARRAY[] = {"10000"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"10000 9999"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"10000 9999"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(3, theObject.getCount(redX, blueX, blueY),0LL);
    }
    {
        string redXARRAY[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"15", "0 250 ", "349"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"2 3 1"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(4, theObject.getCount(redX, blueX, blueY),12LL);
    }
    
    {
        string redXARRAY[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
        vector <string> redX( redXARRAY, redXARRAY+ARRSIZE(redXARRAY) );
        string blueXARRAY[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
        vector <string> blueX( blueXARRAY, blueXARRAY+ARRSIZE(blueXARRAY) );
        string blueYARRAY[] = {"1", " 2 ", "3 4", " 5"};
        vector <string> blueY( blueYARRAY, blueYARRAY+ARRSIZE(blueYARRAY) );
        Ear theObject;
        eq(5, theObject.getCount(redX, blueX, blueY),204LL);
    }
    
  return 0;
}
// END CUT HERE
