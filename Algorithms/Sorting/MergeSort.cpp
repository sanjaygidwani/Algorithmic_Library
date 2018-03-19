// O(N logN)

void merge(int a[], int low, int mid, int high) {
    int n = mid - low + 1;
    int m = high - mid;
    int l[n], r[m];
    for(int i = 0; i < n; i ++) {
        l[i] = a[low + i];
    }
    for(int i = 0; i < m; i ++) {
        r[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while(i < n && j < m) {
        if(l[i] < r[j]) {
            a[k] = l[i];
            i ++;
        }
        else {
            a[k] = r[j];
            j ++;
        }
        k ++;
    }
    while(i < n) {
        a[k] = l[i];
        i ++;
        k ++;
    }
    while(j < m) {
        a[k] = r[j];
        j ++;
        k ++;
    }
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) >> 1;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
    return;
}
