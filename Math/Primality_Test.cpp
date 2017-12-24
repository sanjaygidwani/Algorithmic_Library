// Time Complexity: O(sqrt(N))

bool isPrime(int N) {
	if(N == 1)
		return 0;
	int cnt = 0;
	for(int i = 1; i * i <= N; ++i) {
		if(N % i == 0) {
			if(i * i == N)
				cnt += 1;
			else
				cnt += 2;
		}
		if(cnt > 2)
			return 0;
	}
	return 1;
}
