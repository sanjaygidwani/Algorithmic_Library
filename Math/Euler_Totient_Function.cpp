// Compute Euler Totient Function (ETF) value
// O(sqrt(N))

int phi(int n) {
	int result = n;
	for(int p = 2; p * p <= n; ++ p) {
		if(n % p == 0) {
			while(n % p == 0) {
				n /= p;
			}
			result -= result / p;
		}
	}
	if(n > 1) {
		result -= result / n;
	}
	return result;
}

// Precompute ETF values
// O(N log(N))

long long etf[N];
long long prime[N];
void calc_etf() {
	etf[1] = 1;
	for(long long i = 2; i <= N; i++) {
		if(!prime[i]) {
			etf[i] = i - 1;
			for(long long j = 1; j * i <= N; j++) {
				if(!prime[j * i]) {
					prime[j * i] = i;
				}
			}
		} else {
			etf[i] = etf[prime[i]] * etf[i / prime[i]];
			long long g = 1;
			if(i % (prime[i] * prime[i]) == 0) {
				g = prime[i];
			}
			etf[i] *= g;
			etf[i] /= etf[g];
		}
	}
}
