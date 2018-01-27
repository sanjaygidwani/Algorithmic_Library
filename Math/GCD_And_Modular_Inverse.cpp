// euclid's gcd
// O(log(max(A, B)))

int gcd(int a, int b) {
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// extended euclid's gcd
// O(log(max(A, B)))

int d, x, y;
void extendedEuclid(int a, int b) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclid(b, a % b);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}

// modular inverse, when m is prime
// O(log M)

int modInverse(int a, int m) {
	return fastExpo(a, m - 2, m);
}

// modular inverse
// O(log(max(A, M)))

int modInverse(int a, int m) {
	extendedEuclid(a, m);
	return (x % m + m) % m;
}
