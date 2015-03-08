#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> v1, v2;
char buf[100010];

int main() {
	int n;
	scanf("%d",&n);
	gets(buf);
	while (n--) {
		v1.clear(); v2.clear();
		gets(buf);
		int len = strlen(buf);
		if (buf[len-1] == '\n') buf[--len] = 0;
		for (int i = 1 ; i < len ; ++i) {
			v1.push_back(abs(buf[i] - buf[i-1]));
		}
		for (int i = len - 1 ; i > 0 ; --i) {
			v2.push_back(abs(buf[i] - buf[i-1]));
		}
		int flg = 1;
		for (int i = 0 ; i < v1.size() ; ++i)
			if (v1[i] != v2[i]) {flg = 0; break;}
		if (flg) printf("Funny\n");
		else printf("Not Funny\n");
	}
	return 0;
}

