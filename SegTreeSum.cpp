// http://codeforces.com/profile/MisterMiracle

struct SegTree {
	int sz, start = 1;
	vector<ll> t;

	void init(vector<int>& a) {
		sz = a.size();
		while (start < sz) start *= 2;
		t.resize(4 * a.size());
		for (int i = 0; i < sz; i++) t[start + i] = a[i];
		for (int i = start - 1; i > 0; i--) t[i] = t[2 * i] + t[2 * i + 1];
	}

	ll get(int l, int r) {
		l += start;
		r += start;
		ll sum = 0;
		while (l <= r) {
			if (l % 2) sum += t[l++];
			if (r % 2 == 0) sum += t[r--];
			l /= 2;
			r /= 2;
		}
		return sum;
	}

	void update(int ind, int v) {
		ind += start;
		t[ind] = v;
		while (ind / 2 > 0) {
			ind /= 2;
			t[ind] = t[ind * 2] + t[ind * 2 + 1];
		}
	}
} t;

// http://codeforces.com/profile/MisterMiracle