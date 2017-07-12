ll PowMod(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret % m;
}
ll fac[100005];
ll GetFact(int p) {
    fac[0] = 1;
    for (int i = 1; i <= p; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
}
ll Lucas(ll n, ll m, ll p) {
    ll ret = 1;
    while (n && m) {
        ll a = n % p, b = m % p;
        if (a < b) return 0;
        ret = ret * fac[a] * PowMod(fac[b] * fac[a - b] % p, p - 2, p) % p;
        n /= p;
        m /= p;
    }
    return ret;
}
