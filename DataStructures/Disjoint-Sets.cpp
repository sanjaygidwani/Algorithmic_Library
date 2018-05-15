// union-find algorithm (disjoint sets)
// O(N logN)

int par[N];
int size[N];

void init(int n) {
	for(int i = 1; i <= n; i++) {
		par[i] = i;
		size[i] = 1;
	}
}

int root(int i) {
	while(par[i] != i) {
		par[i] = par[par[i]];
		i = par[i];
	}
	return i;
}

void weighted_union(int a, int b) {
	int root_a = root(a);
	int root_b = root(b);
	if(root_a == root_b)
		return;
	if(size[root_a] < size[root_b]) {
		par[root_a] = par[root_b];
		size[root_b] += size[root_a];
	} 
	else {
		par[root_b] = par[root_a];
		size[root_a] += size[root_b];
	}
}

bool find(int a, int b) {
	if(root(a) == root(b))
		return 1;
	return 0;
}
