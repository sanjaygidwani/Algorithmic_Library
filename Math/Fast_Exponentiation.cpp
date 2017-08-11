// (A ^ B) % M
// O(logB)

long long fast_expo(long long a, long long b, long long md) {
	long long ans = 1;
	while(b > 0) {
		if(b % 2 == 1) {
			ans = (ans * a) % md;
		}
		a = (a * a) % md;
		b = b / 2;
	}
	return ans;
}
