// http://codeforces.com/profile/MisterMiracle

void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
	int ptrA = 0, ptrB = 0;
	while (ptrA < a.size() && ptrB < b.size()) {
		if (a[ptrA] < b[ptrB]) c.emplace_back(a[ptrA++]);
		else c.emplace_back(b[ptrB++]);
	}
	while (ptrA < a.size()) c.emplace_back(a[ptrA++]);
	while (ptrB < b.size()) c.emplace_back(b[ptrB++]);
}

int lowerbound(vector<int>& a, int v) {
	int l = 0, r = a.size() - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (a[m] >= v) r = m;
		else l = m + 1;
	}
	return a[l] == v ? l : -1;
}

int upperbound(vector<int>& a, int v) {
	int l = 0, r = a.size() - 1;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (a[m] <= v) l = m;
		else r = m - 1;
	}
	return a[l] == v ? l : -1;
}

struct SegTree {
	vector<vector<int>> t;
	int size, start = 1;

	void init(vector<int>& a) {
		size = a.size();
		t.resize(4 * size);
		while (start < size) start *= 2;
		for (int i = start; i < start + size; i++) t[i].emplace_back(a[i - start]);
		for (int i = start - 1; i > 0; i--) merge(t[2 * i], t[2 * i + 1], t[i]);
	}

	int get_min(int l, int r) {
		l += start;
		r += start;
		int minv = INT_MAX;
		while (l <= r) {
			if (l % 2) minv = min(minv, t[l][0]);
			if (r % 2 == 0) minv = min(minv, t[r][0]);
			l /= 2;
			r /= 2;
		}
		return minv;
	}

	int get_max(int l, int r) {
		l += start;
		r += start;
		int maxv = INT_MIN;
		while (l <= r) {
			if (l % 2) maxv = max(maxv, t[l].back());
			if (r % 2 == 0) maxv = max(maxv, t[r].back());
			l /= 2;
			r /= 2;
		}
		return maxv;
	}
};

// http://codeforces.com/profile/MisterMiracle