// http://codeforces.com/profile/MisterMiracle

struct minTree {
	int sz, start = 1;
	vector<int> t;

	void init(vector<int> &a) {
		sz = a.size();
		while (start < sz) start *= 2;
		t.resize(4 * a.size, INT_MAX);
		for (int i = 0; i < sz; i++) t[start + i] = i;
		for (int i = start - 1; i > 0; i--) t[i] = min(t[2 * i], t[2 * i + 1]);
	}

	int get(int l, int r) {
		l += start;
		r += start;
		int minv = INT_MAX;
		while (l <= r) {
			if (l & 1) minv = min(minv, t[l++]);
			if (~r & 1) minv = min(minv, t[r--]);
			l /= 2;
			r /= 2;
		}
		return minv;
	}

	void update(int ind, int v) {
		ind += start;
		ind /= 2;
		while (ind > 0) {
			t[ind] = min(t[ind * 2], t[ind * 2 + 1]);
			ind /= 2;
		}
	}
}

// http://codeforces.com/profile/MisterMiracle