/*如果a m中数互质*/
void ex_gcd(long long a, long long b, long long &x, long long &y, long long &d) { //答案记录在d中
    if (!b) {
        d = a, x = 1, y = 0;
    } else {
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
long long inv(long long t, long long p) { //如果不存在，返回-1
    long long d, x, y;
    ex_gcd(t, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}
long long China(int n, long long *a, long long *m) {
    long long M = 1, ret = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) {
        long long w = M / m[i];
        ret = (ret + w * inv(w, m[i]) * a[i]) % M;
    }
    return (ret + M) % M;
}
/*r如果不一定互质*/
typedef long long ll;
long long China(ll A[], LL B[], LL M[], int n) { //求解A[i]x = B[i] (mod M[i]),总共n个线性方程组
    ll x = 0, m = 1;
    for (int i = 0; i < n; i++) {
        long long a = A[i] * m, b = B[i] - A[i] * x, d = __gcd(M[i], a);
        if (b % d != 0) return -1; //答案不存在，返回-1
        LL t = b / d * inv(a / d, M[i] / d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    x = (x % m + m) % m;
    return x; //返回的x就是答案，m是最后的lcm值
}

/*快速*/
ll a[20], b[20], l, r;
int T, n, Cas = 1, vis[20];
ll pow(ll a, ll b, ll p) {
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
ll CRT(ll *a, ll *b, int n) {
    ll ans = 0, P = 1;
    for (int i = 0; i < n; i++)
        if (vis[i]) P *= a[i];
    for (int i = 0; i < n; i++)
        if (vis[i]) ans = (ans + (P / a[i]) * pow(P / a[i], a[i] - 2, a[i]) % P * b[i] % P) % P;
    while (ans < 0) ans += P;
    return ans;
}