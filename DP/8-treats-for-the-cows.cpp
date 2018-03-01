/*
    http://www.spoj.com/problems/TRT/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e3 + 5;
int a[N];
int dp[N][N];
 
int trt(int l, int r, int age) {
    if(l > r)
        return 0;
    if(dp[l][r] == -1)
        dp[l][r] = max(trt(l + 1, r, age + 1) + (a[l] * age), trt(l, r - 1, age + 1) + (a[r] * age));
    return dp[l][r];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << trt(0, n - 1, 1) << "\n";
    return 0;
}
