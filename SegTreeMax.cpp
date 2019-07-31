// http://codeforces.com/profile/MisterMiracle

struct maxTree {
	int sz, start = 1;
	vector<int> t;

	void init(vector<int>& a) {
		sz = a.size();
		while (start < sz) start *= 2;
		t.resize(4 * a.size(), INT_MIN);
		for (int i = 0; i < sz; i++) t[start + i] = a[i];
		for (int i = start - 1; i > 0; i--) t[i] = max(t[2 * i], t[2 * i + 1]);
	}

	int get(int l, int r) {
		l += start;
		r += start;
		int maxv = INT_MIN;
		while (l <= r) {
			if (l % 2) maxv = max(maxv, t[l++]);
			if (r % 2 == 0) maxv = max(maxv, t[r--]);
			l /= 2;
			r /= 2;
		}
		return maxv;
	}

	void update(int ind, int v) {
		ind += start;
		t[ind] = v;
		ind /= 2;
		while (ind > 0) {
			t[ind] = max(t[ind * 2], t[ind * 2 + 1]);
			ind /= 2;
		}
	}
} t;

// http://codeforces.com/profile/MisterMiracle