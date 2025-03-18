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

class TheJediTest {
public:
  int minimumSupervisors(vector <int> a, int K) {
    int n = a.size();
    int best = INF;
    for (int mask = 0 ; mask < (1<<n) ; ++mask) {
      int bal = 0, cost = 0;
      int flg = 1;
      for (int i = 0 ; i < n ; i++) {
        int tmp = a[i] + bal;
        if (tmp < 0) {flg = 0; break;}
        if (mask&(1<<i)) {
          int give = tmp % K;
          if (give > a[i]) {
            bal = give - K;
            tmp += K - give;
          } else {
            bal = give;
          }
          cost += tmp / K;
        } else {
          cost += (tmp + K - 1) / K;
          bal = 0;
        }
      }
      if (flg) {
        if (cost < best) best = cost;
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
        int studentsARRAY[] = {3, 6, 3};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(0, theObject.minimumSupervisors(students, 4),3);
    }
    {
        int studentsARRAY[] = {1, 1, 1, 1};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(1, theObject.minimumSupervisors(students, 4),2);
    }
    {
        int studentsARRAY[] = {0, 0, 0, 0};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(2, theObject.minimumSupervisors(students, 12345),0);
    }
    {
        int studentsARRAY[] = {15, 0, 13, 4, 29, 6, 2};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(3, theObject.minimumSupervisors(students, 7),10);
    }
    {
        int studentsARRAY[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
        vector <int> students( studentsARRAY, studentsARRAY+ARRSIZE(studentsARRAY) );
        TheJediTest theObject;
        eq(4, theObject.minimumSupervisors(students, 114),102138);
    }
  return 0;
}
// END CUT HERE
