// O(N + M)
// N : text length
// M : pattern length

vector<int> v;

void lpsArray(string p, int m, int lps[]) {
    lps[0] = 0;
    int j = 0, i = 1;
    while(i < m) {
        if(p[i] == p[j]) {
            lps[i] = j + 1;
            i ++; 
            j ++;
        }
        else {
            if(j != 0)
                j = lps[j - 1];
            else {
                lps[i] = 0;
                i ++;
            }
        }
    }
}

void kmp(string p, string t) {
    int n = t.length();
    int m = p.length();
    int lps[m];
    lpsArray(p, m, lps);
    int i = 0, j = 0;
    while(i < n) {
        if(t[i] == p[j]) {
            i ++; 
            j ++;
        }
        if(j == m) {
            v.push_back(i - j);
            j = lps[j - 1];
        }
        else if(i < n && t[i] != p[j]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i ++;
        }
    }
}
