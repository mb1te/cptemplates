// http://codeforces.com/profile/MisterMiracle

struct Fenwick {
	ll t[1100000];
	int sz;

	void update(int ind, int v) {
		for (; ind <= sz; ind |= ind + 1) {
			t[ind] += v;
		}
	}

	ll get(int r) {
		ll sum = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			sum += t[r];
		}
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}
}

// http://codeforces.com/profile/MisterMiracle