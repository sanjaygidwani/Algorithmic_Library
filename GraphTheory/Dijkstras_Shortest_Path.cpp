// dijkstras shortest path algorithm
// O(V + E logV)

vector < pair < int, int > > v[N];
bool vis[N];
int parent[N];
long long dist[N];

void dijkstras() {
	for(int i = 0; i <= N; i++) {
		vis[i] = 0;
		parent[i] = -1;
		dist[i] = (long long)(1e18);
	}
	dist[1] = 0;
	multiset < pair < int, int > > ms;
	ms.insert({0, 1});
	while(!ms.empty()) {
		pair < int, int > p = *ms.begin();
		ms.erase(ms.begin());
		int x = p.second; 
		// int w = p.first;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = 0; i < v[x].size(); i++) {
			int p = v[x][i].first, q = v[x][i].second;
			if(dist[x] + q < dist[p]) {
				parent[p] = x;
				dist[p] = dist[x] + q;
				ms.insert({dist[p], p});
			}
		}
	}
}
