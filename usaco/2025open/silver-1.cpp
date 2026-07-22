/* AC: BitOperation + Construction
  Firstly we try to achieve K using minimum sum of values
  We represent K as binary number. If the i-th digit is 1, we add a number (1<<i)-1 to the result.
  For example, if K = 5, i.e. (101b), we add to the answer list 15 (1111b) and 1 (1b).
  Now the sum S of answer list is the minimum sum to achieve K.
  If S > M, clearly no solution. If S == M, we already got the result.
  Otherwise, we want to split the leftover (M-S) so that the xor popcounts is 0.
  Case 1. If (M - S) % 2 == 0, we simply split it to [(M-S)/2, (M-S)/2], the two popcounts canceled by XOR.
  Case 2. If (M - S) % 2 == 1 and (M - S) >= 3, we split it to [1, 2, (M-S-3)/2, (M-S-3)/2].
  Case 3. If (M - S) == 1, then if there is a 1 in previous answer list, we change the 1 to 2. Otherwise, no solution.
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL m, k;
        cin >> m >> k;
        LL tmp = 1;
        vector<LL> counts;
        while (k) {
            if (k & 1) {
                counts.push_back(tmp);
            }
            k /= 2;
            tmp *= 2;
        }
        vector<LL> ans;
        for (auto v: counts) {
            LL tmp = ((LL)1 << v) - 1;
            ans.push_back(tmp);
            m -= tmp;
        }
        if (m < 0) {
            cout << "-1" << endl;
            continue;
        }
        if (m % 2 == 0) {
            ans.push_back(m / 2);
            ans.push_back(m / 2);
        } else if (m >= 3) {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back((m-3) / 2);
            ans.push_back((m-3) / 2);
        } else {    // m == 1
            if (ans[0] == 1) ++ans[0];
            else {
                cout << "-1" << endl;
                continue;
            }
        }
        cout << ans.size() << endl;
        for (int i = 0 ; i < ans.size() ; ++i) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}