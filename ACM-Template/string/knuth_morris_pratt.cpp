int f[];
// text and pattern
int KMP(string t, string p) {
    int m = p.size(), cnt = 0;
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && p[i] != p[j]) j = f[j];
        f[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
    for (int i = 0, j = 0; t[i]; ++i) {
        while (j && t[i] != p[j]) j = f[j];
        j += (t[i] == p[j]);
        // if (j == m) printf("%d\n", i - m + 1);
        if (j == m) cnt++;
    }
    return cnt;
}