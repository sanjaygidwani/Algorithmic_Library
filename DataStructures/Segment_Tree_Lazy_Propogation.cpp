// segment tree lazy propogation, range sum query
// O(N) to build, O(logN) for query and update

long long ar[N];
long long tree[4 * N]; 
long long lazy[4 * N];

void build(int node, int start, int end) {
	if(start == end)
		tree[node] = ar[start];
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void update(int node, int start, int end, int l, int r, long long val) {
	if(lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r) {
		tree[node] += (end - start + 1) * val;
		if(start != end) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int node, int start, int end, int l, int r) {
	if(start > end or start > r or end < l)
		return 0;
	if(lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start >= l and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	long long p1 = query(2 * node, start, mid, l, r);
	long long p2 = query(2 * node + 1, mid + 1, end, l, r);
	return (p1 + p2);
}
