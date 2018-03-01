/*
    http://www.spoj.com/problems/BYTESM2/
*/
#include <bits/stdc++.h>

using namespace std;
 
int dp[105][105];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        int r, c;
        cin >> r >> c;
        for(int i = 0; i < r; i ++) {
            for(int j = 0; j < c; j ++) {
                cin >> dp[i][j];
            }
        }
        for(int i = 1; i < r; i ++) {
            for(int j = 0; j < c; j ++) {
                int stones = -1;
                stones = max(stones, dp[i - 1][j]);
                if(j - 1 >= 0)
                    stones = max(stones, dp[i - 1][j - 1]);
                if(j + 1 < c)
                    stones = max(stones, dp[i - 1][j + 1]);
                dp[i][j] += stones;
            }
        }
        int ans = -1;
        for(int i = 0; i < c; i ++) {
            ans = max(ans, dp[r - 1][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
