void CDQ(long long l, long long r) {
    if (l == r) return;
    long long m = (l + r) / 2;
    CDQ(l, m);
    // 中间操作 l到m
    // int k = 1;
    // while (k <= (2 * (r - l + 1))) k *= 2;
    // for (int i = 0; i < k; i++) {
    //     A[i] = (i + l <= m ? Complex(f[i + l], 0) : Complex(0, 0));
    //     B[i] = (i + 1 <= r - l ? Complex(a[i + 1], 0) : Complex(0, 0));
    // }
    // FFT(A, 1, k);
    // FFT(B, 1, k);
    // for (int i = 0; i < k; i++) {
    //     A[i] = A[i] * B[i];
    // }
    // FFT(A, -1, k);
    // for (int i = m + 1; i <= r; i++) {
    //     ll y = ((int) (A[i - l - 1].real + 0.5)) % MOD;
    //     if ((f[i] += y) >= MOD) f[i] -= MOD;
    //     if (f[i] < 0) f[i] += MOD;
    // }
    CDQ(m + 1, r);
    return;
}