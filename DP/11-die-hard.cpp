/*
    http://www.spoj.com/problems/DIEHARD/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e3 + 5;
int dp[N][N];
 
int f(int x, int y) {
    if(x <= 0 || y <= 0)
        return -1;
    if(dp[x][y] == -1)
        dp[x][y] = max(2 + f(x - 2, y - 8), 2 + f(x - 17, y + 7));
    return dp[x][y];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while(t --) {
        int H, A;
        cin >> H >> A;
        cout << f(H, A) << "\n";
    }
    return 0;
}
