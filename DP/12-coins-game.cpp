/*
    http://www.spoj.com/problems/MCOINS/
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
bool dp[N];
int a[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, k, m;
    cin >> l >> k >> m;
    int _max = -1;
    for(int i = 0; i < m; i ++) {
        cin >> a[i];
        _max = max(_max, a[i]);
    }
    dp[1] = 1;
    for(int i = 2; i <= _max; i ++) {
        if(!dp[i - 1] || (i - l >= 0 && !dp[i - l]) || (i - k >= 0 && !dp[i - k]))
            dp[i] = 1;
    }
    for(int i = 0; i < m; i ++) {
        if(dp[a[i]])
            cout << "A";
        else
            cout << "B";
    }
    cout << "\n";
    return 0;
}
