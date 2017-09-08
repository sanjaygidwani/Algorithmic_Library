// bfs traversal
// O(V + E)

void bfs(int s) {
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for(int i = 0; i < v[p].size(); i++) {
			if(!vis[v[p][i]]) {
 				q.push(v[p][i]);
				vis[v[p][i]] = 1;
			}
		}
	}
}
