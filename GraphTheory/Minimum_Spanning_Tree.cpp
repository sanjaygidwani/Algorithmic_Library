// kruskal algorithm (minimum spanning tree)
// O(E logV)

#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;

int *id = new int[N];
pair <long long, pair<int, int> > p[N];
int nodes, edges;

void init() {
	for(int i = 0; i < N; i++) {
		id[i] = i;
	}
}

int root(int x) {
	while(id[x] != x) {
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void _union(int x, int y) {
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]) {
	int x, y;
	long long cost, minimumCost = 0;
	for(int i = 0; i < edges; i++) {
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x) != root(y)) {
			minimumCost += cost;
			_union(x, y);
		}    
	}
	return minimumCost;
}

int main() {
	init();
	scanf("%d %d", &nodes, &edges);
	int x, y;
	long long weight;
	for(int i = 0; i < edges; i++) {
		scanf("%d %d %lld", &x, &y, &weight);
		p[i] = make_pair(weight, make_pair(x, y));
	}
	sort(p, p + edges);
	long long minimumCost = kruskal(p);
	printf("%lld\n", minimumCost);
	return 0;
}
