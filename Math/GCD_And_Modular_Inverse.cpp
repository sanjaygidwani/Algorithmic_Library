// euclid's gcd
// O(log(max(A, B)))

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

// extended euclid's gcd
// O(log(max(A, B)))

int d, x, y;
void extended_euclid(int a, int b) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extended_euclid(b, a % b);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}

// modular inverse when m is prime
// O(logM)

int mod_invrs(int a, int m) {
	return fast_expo(a, m - 2, m);
}

// modular inverse
// O(log(max(A, M)))

int mod_invrs(int a, int m) {
	extended_euclid(a, m);
	return (x % m + m) % m;
}
