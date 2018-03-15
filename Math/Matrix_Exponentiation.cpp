// Nth Fibonacci Number
// O(logN)

void multiply(long long a[][2], long long b[][2], long long c[][2]) {
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            c[i][j] = 0;
            for(int k = 0; k < 2; k ++) {
                c[i][j] = ((c[i][j] % md) + (((a[i][k] % md) * (b[k][j] % md)) % md)) % md;
            }
        }
    }
}

void power(long long Z[][2], long long n, long long ans[][2]) {
    long long temp[2][2];
    ans[0][0] = 1, ans[0][1] = 0;
    ans[1][0] = 0, ans[1][1] = 1;
    while(n) {
        if(n & 1) {
            multiply(ans, Z, temp);
            for(int i = 0; i < 2; i ++) {
                for(int j = 0; j < 2; j ++) {
                    ans[i][j] = temp[i][j];
                }
            }
        }
        multiply(Z, Z, temp);
        for(int i = 0; i < 2; i ++) {
            for(int j = 0; j < 2; j ++) {
                Z[i][j] = temp[i][j];
            }
        }
        n = (n >> 1);
    }
}

long long fib(long long n) {
    long long f;
    if(n > 2) {
        long long Z[2][2] = {{1, 1}, {1, 0}};
        long long result[2][2];
        power(Z, n - 2, result);
        f = result[0][0] * 1 + result[0][1] * 0;
    }
    else
        f = n - 1;
    return f;
}
