// precompute prime numbers
// O(N log(logN))

bool prm[N];
void sieve() {
	memset(prm, 1, sizeof(prm));
	prm[0] = 0;
	prm[1] = 0;
	for(int i = 2; i * i <= N; ++i) {
		if(prm[i]) {
			for(int j = i * i; j <= N; j += i) {
				prm[j] = 0;
			}
		}
	}
}

// segmented sieve, primes between L to R
// O(sqrt(R)

bool p[r - l + 1];
for(long long i = 0; i < r - l + 1; i++) {
	p[i] = 1;
}
for(long long i = 2; i * i <= r; ++i) {
	for(long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
		p[j - l] = 0;
	}
}
for(long long i = max(l, (long long)(2)); i <= r; ++i) {
	if(p[i - l]) {
		// i is prime
	}
}
