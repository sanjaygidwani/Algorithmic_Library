/**
 * Time Complexity: O(N * LogN)
 * Space Complexity: O(N)
 **/

int par[N]; // par[i] = -1, for all i from 1 to N

int root(int x) {
    int node = x;
    int parent = par[node];
    while(parent > 0) {
        node = parent;
        parent = par[node];
    }
    if(node != x) // collapsing find
        par[x] = node;
    return node;
}

void weighted_union(int u, int v) {
    int ru = root(u);
    int rv = root(v);
    if(ru == rv)
        return;
    if(abs(par[ru]) < abs(par[rv])) {
        par[rv] += par[ru];
        par[ru] = rv;
    } else {
        par[ru] += par[rv];
        par[rv] = ru;
    }
    return;
}
