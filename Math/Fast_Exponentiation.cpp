// (A ^ B) % M
// O(log B)

int fastExpo(int a, int b, int md) {
	int ans = 1;
	while(b > 0) {
		if(b % 2 == 1)
			ans = (ans * a) % md;
		a = (a * a) % md;
		b = b / 2;
	}
	return ans;
}
