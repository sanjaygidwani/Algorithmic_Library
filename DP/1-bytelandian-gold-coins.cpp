/*
    http://www.spoj.com/problems/COINS/
*/
#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;

long long coins(long long n) {
    if(mp.count(n))
        return mp[n];
    mp[n] = max(n, coins(n / 2) + coins(n / 3) + coins(n / 4));
    return mp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp[0] = 0;
    mp[1] = 1;
    long long n;
    while(cin >> n) {
        cout << coins(n) << endl;
    }
    return 0;
}
