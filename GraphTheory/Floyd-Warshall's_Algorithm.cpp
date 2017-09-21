// shortest path from each node to every other node
// O(N ^ 3)

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++) {
		i == j ? dist[i][j] = 0 : dist[i][j] = INF;
	}
}

for(int k = 1; k <= n; k++) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}
