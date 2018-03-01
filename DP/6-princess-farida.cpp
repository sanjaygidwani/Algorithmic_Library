/*
    http://www.spoj.com/problems/FARIDA/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 5;
long long a[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int foo = 1; foo <= t; foo ++) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        long long incl = a[0];
        long long excl = 0;
        for(int i = 1; i < n; i ++) {
            long long var = max(excl, incl);
            incl = excl + a[i];
            excl = var;
        }
        cout << "Case " << foo << ": ";
        cout << max(incl, excl) << "\n";
    }
    return 0;
}
