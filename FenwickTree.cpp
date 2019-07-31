// http://codeforces.com/profile/MisterMiracle

struct Fenwick {
	ll t[1100000] = {};
	int sz;

	ll get(int r) {
		ll sum = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			sum += t[r];
		}
		return sum;
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void update(int ind, int v) {
		v -= get(ind, ind);
		for (; ind <= sz; ind |= ind + 1) {
			t[ind] += v;
		}
	}
} t;

// http://codeforces.com/profile/MisterMiracle