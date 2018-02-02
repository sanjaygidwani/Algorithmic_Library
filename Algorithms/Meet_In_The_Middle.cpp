// maximum sum subset having sum <= s (10 ^ 18), n (40), ai (10 ^ 12)
// O(2 ^ (N / 2) * N)

long long X[2000005];
long long Y[2000005];

void calcsubarray(long long a[], long long x[], int n, int c) {
	for(int i = 0; i < (1 << n); i++) {
		long long s = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				s += a[j + c];
			}
		}
		x[i] = s;
	}
}

long long subsetsum(long long a[], int n, long long S) {
	calcsubarray(a, X, n / 2, 0);
	calcsubarray(a, Y, n - (n / 2), n / 2);
	int size_X = 1 << (n / 2);
	int size_Y = 1 << (n - n / 2);
	sort(Y, Y + size_Y);
	long long max = 0;
	for(int i = 0; i < size_X; i++) {
		if(X[i] <= S) {
			int p = lower_bound(Y, Y + size_Y, S - X[i]) - Y;
			if(p == size_Y || Y[p] != (S - X[i])) {
				p--;
			} 
			if((Y[p] + X[i]) > max) {
				max = Y[p] + X[i];
			}
		}
	}
	return max;
}
