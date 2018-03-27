/*
    http://www.spoj.com/problems/ACPC10D/
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
long long dp[N][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, test = 1;
    while(cin >> n) {
        if(n == 0)
            break;
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i ++) {
            cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
            if(i == 0) {
                dp[i][2] += dp[i][1];
            }
            else if(i == 1) {
                dp[i][0] += dp[i - 1][1];
                dp[i][1] += min(dp[i][0], min(dp[i - 1][1], dp[i - 1][2]));
                dp[i][2] += min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
            }
            else {
                dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] += min(min(dp[i][0], dp[i - 1][0]), min(dp[i - 1][1], dp[i - 1][2]));
                dp[i][2] += min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
            }
        }
        cout << test << ". ";
        cout << dp[n - 1][1] << "\n";
        test ++;
    }
    return 0;
}
