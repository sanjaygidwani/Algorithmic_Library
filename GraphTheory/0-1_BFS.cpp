// 0 - 1 bfs, shortest path between two nodes
// O(V + E)

vector<pair<int, int> > edges[N];
int dist[N];

void bfs(int start) {
	deque <int> Q;
	Q.push_back(start);
	dist[start] = 0;
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop_front();
		for(int i = 0; i < edges[v].size(); i++) {
			if(dist[edges[v][i].first] > dist[v] + edges[v][i].second) {
				dist[edges[v][i].first] = dist[v] + edges[v][i].second;
				if(edges[v][i].second == 0)
					Q.push_front(edges[v][i].first);
				else
					Q.push_back(edges[v][i].first);
			}
		}
	}
}
