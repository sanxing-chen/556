// C(m, n)
void init() {
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = ((ll) C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}
void init() {
    C[0] = 1;
    int m = 10;
    REP(i, 1, m + 1) {
        C[i] = (ll) C[i - 1] * (m - i + 1) / i % MOD;
    }
}