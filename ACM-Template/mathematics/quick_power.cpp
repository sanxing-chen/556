// p < 1e9
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}

// p > 1e9
ll qmul(ll a, ll b, ll p) { // return a*b %p
    ll t = 0;
    for (; b; a = a * 2 % p, b >>= 1) {
        if (b & 1) t = (t + a) % p;
    }
    return t;
}
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1, a = qmul(a, a, p))
        if (b & 1) t = qmul(t, a, p);
    return t;
}