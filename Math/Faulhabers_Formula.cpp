// 1^k + 2^k + 3^k + ..... + n^k
// n <= 10^18, k <= 1000
// O(k^2)

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 9;
const int N = 1e3 + 5;

long long f[N];
long long B[N], D[N];
long long d, x, y;

long long fastExpo(long long a, long long b) {
	long long ans = 1;
	while(b > 0) {
		if(b % 2 == 1) {
			ans = ((ans % M) * (a % M)) % M;
		}
		a = ((a % M) * (a % M)) % M;
		b = b / 2;
	}
	return ans;
}

void extendedEuclid(long long a, long long b) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclid(b, a % b);
		long long tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}

long long modInverse(long long a, long long m) {
	extendedEuclid(a, m);
	return (x % m + m) % m;
}

void factorials() {
	f[0] = 1;
	for(int i = 1; i < N; i ++) {
		f[i] = (f[i - 1] % M * i) % M;
	}
}

long long nCr(long long n, long long r) {
	long long t = ((f[r] % M) * (f[n - r] % M)) % M;
	return ((f[n] % M) * ((modInverse(t, M)) % M)) % M;
}

void bernoulliNumbers() {
	for(int i = 0; i < N; i ++) {
		B[i] = 0;
		D[i] = 1;
	}
	B[0] = 1, D[0] = 1;
	B[1] = 1, D[1] = 2;
	for(int i = 2; i < N - 1; i += 2) {
		long long I = i + 1;
		long long mul = 1, sum = 0;
		for(int j = 0; j < i; j ++) {
			mul = ((mul % M) * (D[j] % M)) % M;
		}
		for(int j = 0; j < i; j ++) {
			long long t = (((nCr(i, j) * (B[j] % M)) % M) * (mul % M)) % M;
			t = ((t % M) * (f[i + 1] % M)) % M;
			t = ((t % M) * (modInverse(I, M))) % M;
			t = ((t % M) * (modInverse(D[j], M))) % M;
			sum = ((sum % M) + (t % M)) % M;
			I --;
		}
		D[i] = ((mul % M) * (f[i + 1] % M)) % M;
		B[i] = ((D[i] % M) - (sum % M) + M) % M;
	}
}

int main() {
	cin.sync_with_stdio(false);
	factorials();
	bernoulliNumbers();
	int q;
	cin >> q;
	while(q --) {
		long long n, k;
		cin >> n >> k;
		long long mul = 1, sum = 0;
		for(int i = 0; i <= k; i ++) {
			mul = ((mul % M) * (D[i] % M)) % M;
		}
		for(int i = 0; i <= k; i ++) {
			long long t = (fastExpo(n % M, k + 1 - i) * (nCr(k + 1, i) % M)) % M;
			t = ((t % M) * (B[i] % M)) % M;
			t = ((t % M) * (mul % M)) % M;
			t = ((t % M) * (modInverse(D[i], M))) % M;
			sum = ((sum % M) + (t % M)) % M;
		}
		mul = ((mul % M) * ((k + 1) % M)) % M;
		sum = ((sum % M) * (modInverse(mul, M))) % M;
		cout << sum << endl;
	}
	return 0;
}
