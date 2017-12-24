// Time Complexity: O(sqrt(N))

vector<int> allFactors(int N) {
    vector<int> v, res;
    for(int i = 1; i <= sqrt(N); i ++) {
        if(N % i == 0) {
            if(N / i == i)
                res.push_back(i);
            else {
                res.push_back(i);
                v.push_back(N / i);
            }
        }
    }
    for(int i = v.size() - 1; i >= 0; i --)
        res.push_back(v[i]);
    return res;
}
