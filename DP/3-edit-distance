/*
    http://www.spoj.com/problems/EDIST/
*/
#include <bits/stdc++.h>

using namespace std;
 
const int N = 2e3 + 5;
int dp[N][N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        string a, b;
        cin >> a >> b;
        for(int i = 0; i <= a.length(); i ++) {
            for(int j = 0; j <= b.length(); j ++) {
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else if(a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
        cout << dp[a.length()][b.length()]  << "\n";
    }
    return 0;
}
