/**
 * Recursive DFS (Depth First Search) traversal
 * Time Complexity: O(V + E)
 */

void dfs(vector<int> graph[], bool vis[], int src) {
    vis[src] = 1;
    for(int i = 0; i < graph[src].size(); i ++) {
        if(!vis[graph[src][i]]) {
            dfs(graph, vis, graph[src][i]);
        }
    }
    return;
}
