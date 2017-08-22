// check if the number is prime or not
// O(sqrt(N))

bool prm_chk(int N) {
	int cnt = 0;
	for(int i = 1; i * i <= N; ++i) {
		if(N % i == 0) {
			if(i * i == N) {
				cnt += 1;
			} else {
				cnt += 2;
			}
		}
		if(cnt > 2) {
			return 0;
		}
	}
	return 1;
}
