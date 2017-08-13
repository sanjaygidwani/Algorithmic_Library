// segment tree, range minimum query
// O(N) to build, O(logN) for query and update

void build(int ar[], int tree[], int node, int start, int end) {
	if(start == end) {
		tree[node] = ar[start];
	} else {
		int mid = (start + end) / 2;
		build(ar, tree, 2 * node, start, mid);
		build(ar, tree, 2 * node + 1, mid + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int tree[], int node, int start, int end, int l, int r) {
	if(r < start || end < l) {
		return int(1e9);
	}
	if(l <= start && end <= r) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int p1 = query(tree, 2 * node, start, mid, l, r);
	int p2 = query(tree, 2 * node + 1, mid + 1, end, l, r);
	return min(p1, p2);
}

void update(int tree[], int node, int start, int end, int idx, int val) {
	if(start == end) {
		tree[node] = val;
	} else {
		int mid = (start + end) / 2;
		if(start <= idx && idx <= mid) {
			update(tree, 2 * node, start, mid, idx, val);
		} else {
			update(tree, 2 * node + 1, mid + 1, end, idx, val);
		}
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}
