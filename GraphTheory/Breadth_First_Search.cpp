/**
 * BFS (Breadth First Search) traversal
 * Time Complexity: O(V + E)
 *
 * Global declarations: vector<bool> vis(V, 0), vector<int> graph[V]
 */
 
void bfs(int src) {
    queue <int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i = 0; i < graph[p].size(); i ++) {
            if(!vis[graph[p][i]]) {
                q.push(graph[p][i]);
                vis[graph[p][i]] = 1;
            }
        }
    }
    return;
}
