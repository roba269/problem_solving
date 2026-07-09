#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1e5+10;
string buf;
int leftp[26][MAXN], rightp[26][MAXN];

int main() {
    int n, q;
    cin >> n >> q;
    cin >> buf;
    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
        int cur = -1;
        for (int i = 0 ; i < n ; ++i) {
            if (buf[i] == ch) cur = i;
            leftp[ch-'a'][i] = cur;
        }
        cur = n;
        for (int i = n-1 ; i >= 0 ; --i) {
            if (buf[i] == ch) cur = i;
            rightp[ch-'a'][i] = cur;
        }
    }
    while (q--) {
        long long ans = -1;
        int L, R;
        cin >> L >> R;
        --L; --R;
        for (char c1 = 'a' ; c1 <= 'z'; ++c1) {
            for (char c2 = 'a' ; c2 <= 'z' ; ++c2) {
                if (c1 == c2) continue;
                int tl = rightp[c1-'a'][L];
                int tr = leftp[c2-'a'][R];
                if (tl >= tr) continue;

                int mid = (tl + tr) / 2;
                
                int tmp = leftp[c2-'a'][mid];
                if (tmp > tl && tmp < tr) {
                    ans = max(ans, (long long)(tmp - tl) * (tr - tmp));
                }
                if (mid + 1 < n) {
                    tmp = rightp[c2-'a'][mid+1];
                    if (tmp > tl && tmp < tr) {
                        ans = max(ans, (long long)(tmp - tl) * (tr - tmp));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}