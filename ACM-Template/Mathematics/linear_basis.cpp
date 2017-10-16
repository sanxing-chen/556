const int MAX_N = 100000 + 3, MAX_BASE = 60;
int n, zero = false;
ll a[MAX_N], b[MAX_BASE + 3];
vector<ll> mmap;
void prepare() {
    int cnt = 0;
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i], cnt++;
                    for (int k = j - 1; k >= 0; --k) if (b[k] && ((b[j] >> k) & 1)) b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k) if ((b[k] >> j) & 1) b[k] ^= b[j];
                    break;
                }
            }
    zero = cnt != n;

    mmap.clear();
    for (int i = 0; i <= MAX_BASE; ++i)
        if (b[i]) mmap.push_back(b[i]);
}
//faster:
     REP(i, 0, n) {
        for (int j = 62; j >= 0; j--) {
            if (!(a[i] >> j)) continue; //对线性基的这一位没有贡献
            if (!p[j]) {
                p[j] = a[i];
                break;
            }
            a[i] ^= p[j];
        }
    }