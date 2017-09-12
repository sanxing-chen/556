
ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b != 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll comb(ll a, ll b, ll p) {
    if (a < b) return 0;
    if (a == b) return 1;
    if (b > a - b) b = a - b;

    ll ans = 1, ca = 1, cb = 1;
    for (ll i = 0; i < b; ++i) {
        ca = (ca * (a - i)) % p;
        cb = (cb * (b - i)) % p;
    }
    ans = (ca * powmod(cb, p - 2, p)) % p;
    return ans;
}

ll Lucas(int n, int m, int p) {
    ll ans = 1;

    while (n && m && ans) {
        ans = (ans * comb(n % p, m % p, p)) % p;
        n /= p;
        m /= p;
    }
    return ans;
}