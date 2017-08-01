// search for element in the array which is just greater than the given element.

int binary_search(int ar[], int n, int element) {
	int l = 0, r = n;
	while(l < r) {
		int mid = (l + r) / 2;
		if(ar[mid] > element)
			r = mid;
		else
			l = mid + 1;
	}
	if(ar[l] > element)
		return l;
	return -1;
}
