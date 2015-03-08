#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

const int MAXN = 100010;
int a[MAXN];
int lt[MAXN], rt[MAXN];

stack<pair<int,int> > stk, stk2;

int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&a[i]);
		
		for (int i = 0 ; i < n ; ++i) {
			while (!stk.empty() && a[i] >= stk.top().first) {
				stk.pop();
			}
			if (stk.empty()) lt[i] = 0;
			else lt[i] = stk.top().second + 1;
			stk.push(make_pair(a[i], i));
		}
		
		for (int i = n-1 ; i >= 0 ; --i) {
			while (!stk2.empty() && a[i] >= stk2.top().first) {
				stk2.pop();
			}
			if (stk2.empty()) rt[i] = 0;
			else rt[i] = stk2.top().second + 1;
			stk2.push(make_pair(a[i], i));
		}
		// for (int i = 0 ; i < n ; ++i)
		// 	printf("[%d,%d]\n", lt[i], rt[i]);
		long long ans = 0;
		for (int i = 0 ; i < n ; ++i) {
			long long tmp = (long long)lt[i] * rt[i];
			if (tmp > ans) ans= tmp;
		}
		cout << ans << endl;
	}
	return 0;
}

