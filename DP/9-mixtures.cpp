/*
    http://www.spoj.com/problems/MIXTURES/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 5;
int a[N];
long long dp[N][N];
 
long long csum(int s, int e) {
    long long sum = 0;
    for(int i = s; i <= e; i ++) {
        sum += a[i];
        sum %= 100;
    }
    return sum;
}
 
long long f(int i, int j) {
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = 1e18;
    for(int k = i; k <= j; k ++) {
        dp[i][j] = min(dp[i][j], f(i, k) + f(k + 1, j) + (csum(i, k) * csum(k + 1, j)));
    }
    return dp[i][j];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout << f(0, n - 1) << "\n";
    }
    return 0;
}
