/* SRM 561 Div 1 Lev 1 */
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

typedef vector<int> VI;

#define PB push_back
#define MP make_pair

typedef long long LL;
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;

class ICPCBalloons {
public:
  int get_ans(VI have, VI need) {
    if (need.size() == 0) return 0;
    int tot = 0;
    for (int i = 0 ; i < have.size() ; ++i)
      tot += have[i];
    for (int i = 0 ; i < need.size() ; ++i)
      tot -= need[i];
    if (tot < 0) return INF;
    sort(have.begin(), have.end());
    sort(need.begin(), need.end());
    int dp[16][52];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0 ; i <= need.size() ; ++i) {
      for (int j = 0 ; j <= have.size() ; ++j) {
        if (i == 0 && j == 0) continue;
        if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
        if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + need[i-1]);
        if (i && j) dp[i][j] = min(dp[i][j],
          dp[i-1][j-1] + (need[i-1] <= have[j-1] ? 0 : need[i-1] - have[j-1]));
      }
    }
    return dp[need.size()][have.size()];
  }
  int minRepaintings(vector <int> bc, string bs, vector <int> ac) {
    int res = INF;
    int mcnt = 0, lcnt = 0;
    VI m_have, l_have;
    for (int i = 0 ; i < bc.size() ; ++i)
      if (bs[i] == 'M') m_have.PB(bc[i]);
      else l_have.PB(bc[i]);
    int np = ac.size();
    for (int mask = 0 ; mask < (1<<np) ; ++mask) {
      vector<int> ml, ll;
      for (int i = 0 ; i< np ; ++i)
        if (mask & (1<<i)) {
          ml.PB(ac[i]);
        } else {
          ll.PB(ac[i]);
        }
      int ans = get_ans(m_have, ml) + get_ans(l_have, ll);
      if (ans >= INF) continue;
      if (ans < res) res = ans;
    }
    if (res >= INF) return -1;
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
        int balloonCountARRAY[] = {100};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {1,2,3,4,5};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(0, theObject.minRepaintings(balloonCount, "L", maxAccepted),10);
    }
    
    {
        int balloonCountARRAY[] = {100};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {10,20,30,40,50};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(1, theObject.minRepaintings(balloonCount, "M", maxAccepted),-1);
    }
    
    {
        int balloonCountARRAY[] = {5,6,1,5,6,1,5,6,1};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {7,7,4,4,7,7};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(2, theObject.minRepaintings(balloonCount, "MLMMLMMLM", maxAccepted),6);
    }
    
    {
        int balloonCountARRAY[] = {100,100};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {50,51,51};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(3, theObject.minRepaintings(balloonCount, "ML", maxAccepted),-1);
    }
    {
        int balloonCountARRAY[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(4, theObject.minRepaintings(balloonCount, "MMMLLLMMLLMLMLM", maxAccepted),5);
    }
    {
        int balloonCountARRAY[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
        vector <int> balloonCount( balloonCountARRAY, balloonCountARRAY+ARRSIZE(balloonCountARRAY) );
        int maxAcceptedARRAY[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
        vector <int> maxAccepted( maxAcceptedARRAY, maxAcceptedARRAY+ARRSIZE(maxAcceptedARRAY) );
        ICPCBalloons theObject;
        eq(5, theObject.minRepaintings(balloonCount, "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL", maxAccepted),210);
    }
    
  return 0;
}
// END CUT HERE
