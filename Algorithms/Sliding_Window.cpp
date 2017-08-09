// maximum sum of a contiguous subarray of size k
// O(N)

int sliding_window(int ar[], int n, int k) {
	if(n < k) {
		return -1;
	}
	int mx = 0;
	for(int i = 0; i < k; i++) {
		mx += ar[i];
	}
	int cur = mx;
	for(int i = k; i < n; i++) {
		cur += ar[i] - ar[i - k];
		mx = max(mx, cur);
	}
	return mx;
}
