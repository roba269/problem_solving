#include <cstdio>

typedef long long LL;
typedef pair<LL, LL> SEG;

int sg[105][105];

int get_sg(int a, int b) {
	if (sg[a][b] != -1) return sg[a][b];
	if (a == 0) {
		return sg[a][b] = 0;
	}
	set<int> visit;
	for (int la = 0 ; la <= a-1 ; ++la) {
		for (int lb = 0 ; lb <= b ; ++lb) {
			int tmp = (get_sg(a-1, lb) ^ get_sb(a-1, b-lb));
			visit.insert(tmp);
		}
	}
	for (int lb = b+1 ; lb <= 100 ; ++lb) {
		int tmp = (get_sg(a-1, lb) ^ get_sb(a-1, 100));
		visit.insert(tmp);
	}
	for (int res = 0 ; ; ++res) {
		if (visit.find(res) == visit.end()) {
			return sg[a][b] = res;
		}
	}
}

inline bool isvalid(SEG s) {
	return s.first <= s.second;
}

vector<SEG> make_move(const vector<SEG>& input, LL move) {
	vector<SEG> result;
	for (int i = 0 ; i < input.size() ; ++i) {
		if (move >= input[i].first && move <= input[i].second) {
			SEG s1 = make_pair(input[i].first, move-1);
			SEG s2 = make_pair(move+LEN, input[i].second);
			if (isvalid(s1)) result.push_back(s1);
			if (isvalid(s2)) result.push_back(s2);
		} else {
			result.push_back(input[i]);
		}
	}
	return result;
}

LL pick_my_move(const vector<SEG>& input) {
	for (int i = 0 ; i < input.size() ; ++i) {
		int sg_value = 0;
		for (int j = 0 ; j < input.size() ; ++j) {
			if (j == i) continue;
			int seg_count = (input[j].second - input[j].first + 1) / LEN;
			int seg_mod = (input[j].second - input[j].first + 1) % LEN;
			sg_value ^= get_sg(seg_count, seg_mod);
		}

		int seg_count = (input[i].second - input[i].first + 1) / LEN;
		int seg_mod = (input[i].second - input[i].first + 1) % LEN;
		for (int possible_move = 0 ; possible_move <= seg_mod ; ++possible_move) {

		}

		for (LL p = input[i].first ; p + LEN - 1 <= input[i].second ; ++p) {
			vector<SEG> tmp = make_move(input, p);
			if (!can_win(tmp)) return p;
		}
	}
}

int main() {
	int T, W;
	scanf("%d%d",&T,&W);
	for (int ca = 1 ; ca <= T ; ++ca) {
		vector<pair<long long, long long> > segs;
		segs.push_back(make_pair(1LL, 1000000000000LL));
		long long p;
		scanf("%lld", p);
		if (p < 0) {
			continue;
		}
		segs = make_move(segs, p);

		long long my_move = pick_my_move(segs);
		printf("%d\n", my_move);
		fflush(stdout);
		segs = make_move(segs, p);
	}
	return 0;
}