/*
    http://www.spoj.com/problems/AIBOHP/
*/
#include <bits/stdc++.h>

using namespace std;
 
const int N = 7e3 + 5;
int dp[N][N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        string s;
        cin >> s;
        int n = s.length();
        string r = s;
        reverse(r.begin(), r.end());
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= n; j ++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s[i - 1] == r[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << n - dp[n][n] << endl;
    }
    return 0;
}
