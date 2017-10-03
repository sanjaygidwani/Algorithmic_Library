// contiguous sub-array with maximum sum
// O(N)

long long kadane_algo(int ar[], int n) {
  long long max_so_far = ar[0];
  long long cur_max = ar[0];
  for(int i = 1; i < n; i++) {
    cur_max = max(ar[i], ar[i] + cur_max);
    max_so_far = max(max_so_far, cur_max);
  }
  return max_so_far;
}
