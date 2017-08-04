// recursive dfs traversal.
// O(V + E)

void dfs(vector <int> v[], bool vis[], int s) {
	vis[s] = 1;
    	for(int i = 0; i < v[s].size(); i++) {
    		if(!vis[v[s][i]]) {
			dfs(v, vis, v[s][i]);
		}
    	}
}

// path finding using dfs.
// O(V + E)

void dfs(vector <int> v[], int path[], int path_index, bool vis[], int s, int d) {
    	vis[s] = 1;
    	path[path_index] = s;
    	path_index += 1;
    	if(s == d) {
		// to do
		return;
    	} else {
        	for(int i = 0; i < v[s].size(); i++) {
            		if(!vis[v[s][i]]) {
            			dfs(v, path, path_index, vis, v[s][i], d);
            		}
        	}
    	}
    	path_index -= 1;
    	vis[s] = 0;
}
