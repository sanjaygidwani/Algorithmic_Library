/*
  http://www.spoj.com/problems/PIGBANK/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        int E, W;
        cin >> E >> W;
        int n;
        cin >> n;
        int val[n], wt[n];
        for(int i = 0; i < n; i ++) {
            cin >> val[i] >> wt[i];
        }
        W -= E;
        int dp[W + 1];
        dp[0] = 0;
        for(int i = 1; i <= W; i ++) {
            dp[i] = -1;
            for(int j = 0; j < n; j ++) {
                if(wt[j] <= i && dp[i - wt[j]] != -1 && (dp[i] == -1 || dp[i - wt[j]] + val[j] < dp[i]))
                    dp[i] = dp[i - wt[j]] + val[j];
            }
        }
        if(dp[W] == -1)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[W] << ".\n";
    }
    return 0;
}
