#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 50;
vector<pair<int,int> > p;

int main() {
	for (int i = 0 ; i <= MAXN ; ++i)
		for (int j = 0 ; j <= MAXN ; ++j) {
			if (i == 0 && j == 0) continue;
			p.push_back(make_pair(i, j));
		}
	printf("%d\n", p.size());
	for (int i = 0 ; i < p.size() ; ++i)
		printf("%d %d\n", p[i].first, p[i].second);
	return 0;
}