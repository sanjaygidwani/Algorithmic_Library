/*
    http://www.spoj.com/problems/PARTY/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W, n;
    while(cin >> W >> n) {
        if(W == 0 && n == 0)
            break;
        int wt[n], val[n];
        for(int i = 0; i < n; i ++) {
            cin >> wt[i] >> val[i];
        }
        int dp[n + 1][W + 1], tWeight;
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= W; j ++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                if(dp[i][j] > dp[i][j - 1])
                    tWeight = j;
            }
        }
        cout << tWeight << " " << dp[n][W] << "\n";
    }
    return 0;
}
