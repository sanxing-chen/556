ll exgcd(ll a, ll b, ll &x, ll &y) {
    return (!b) ? (x = 1, y = 0, a = a) : (d = exgcd(b, a % b, y, x), y -= x * (a / b), d = d);
}