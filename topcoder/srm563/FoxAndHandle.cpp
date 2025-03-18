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
const int INF = 1000100100;
const LL LLINF = (LL)INF * INF;
int cnt[26];

class FoxAndHandle {
public:
  int possible(char *cur, string S) {
    // printf("S:%s try:%s\n",S.c_str(),cur);
    int tmp[26];
    memset(tmp, 0, sizeof(tmp));
    int p = 0;
    for (int i = 0 ; i < strlen(cur) ; ++i, ++p) {
      while (p < S.size() && S[p] != cur[i]) ++p;
      if (p == S.size()) return 0;
      // ++tmp[S[p]-'a'];
    }
    // printf("p:%d\n",p);
    for (; p < S.size() ; ++p) {
      ++tmp[S[p]-'a'];
    }
    for (int i = 0 ; i < 26 ; i++) {
      // printf("ch:%c tmp:%d cnt:%d\n", i+'a', tmp[i], cnt[i]);
      if (tmp[i] < cnt[i]) return 0;
    }
    return 1;
  }
  string lexSmallestName(string S) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0 ; i < S.size() ; ++i)
      ++cnt[S[i]-'a'];
    for (int i = 0 ; i < 26 ; ++i) cnt[i] >>= 1;
    /*
    char ts[64];
    int len = 0;
    for (int i = 0 ; i < 26 ; ++i) {
      for (int k = 0 ; k < cnt[i] ; ++k)
        ts[len++] = i + 'a';
    }
    ts[len] = 0;
    */
    
    int len = S.size() / 2;
    char res[64];
    memset(res, 0, sizeof(res));
    for (int i = 0 ; i < len ; ++i) {
      for (int j = 0 ; j < 26 ; j++) {
        if (cnt[j]) {
          --cnt[j];
          res[i] = j + 'a';
          if (possible(res, S)) break;
          ++cnt[j];
        }
      }
    }
    return (string)res;
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
        FoxAndHandle theObject;
        eq(0, theObject.lexSmallestName("foxfox"),"fox");
    }
    {
        FoxAndHandle theObject;
        eq(1, theObject.lexSmallestName("ccieliel"),"ceil");
    }
    {
        FoxAndHandle theObject;
        eq(2, theObject.lexSmallestName("abaabbab"),"aabb");
    }
    {
        FoxAndHandle theObject;
        eq(3, theObject.lexSmallestName("bbbbaaaa"),"bbaa");
    }
    
    {
        FoxAndHandle theObject;
        eq(4, theObject.lexSmallestName("fedcbafedcba"),"afedcb");
    }
    {
        FoxAndHandle theObject;
        eq(5, theObject.lexSmallestName("nodevillivedon"),"deilvon");
    }
    
  return 0;
}
// END CUT HERE
