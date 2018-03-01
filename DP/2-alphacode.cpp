/*
    http://www.spoj.com/problems/ACODE/
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
long long dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin >> s) {
        if(s == "0")
            break;
        memset(dp, 0, sizeof dp);
        dp[-1] = 1;
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] != '0')
                dp[i] += dp[i - 1];
            string t = "";
            t += s[i - 1];
            t += s[i];
            int num;
            stringstream sts;
            sts << t;
            sts >> num;
            if(i - 2 >= -1 && num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        cout << dp[s.length() - 1] << endl;
    }
    return 0;
}
