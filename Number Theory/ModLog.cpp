//O(root(m))
int modLog(int a, int b, int m) {
    int n = (int) sqrtl(m) + 1, e = 1, f = 1, j = 1;
    unordered_map<int, int> A;
    while (j <= n && (e = f = e * a % m) != b % m)
        A[e * b % m] = j++;
    if (e == b % m) return j;
    if (__gcd(m, e) == __gcd(m, b))
        for(int i=2;i<n+2;i++) if (A.count(e = e * f % m))
                return n * i - A[e];
    return -1;
}
// (modLog(2,15,29)): 27
// (modLog(3,15,29)): 11