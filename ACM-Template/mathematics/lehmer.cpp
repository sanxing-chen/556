//模板1，代码量、占用空间较小，时间复杂度稍高，大概O（n^(3/4)）
// Lehmer算法求解 n以内的质数个数。
//π(m)=ϕ(m,n)+n−1−P2(m,n)
//其中
//ϕ(m,0)=m
//ϕ(m,n)=ϕ(m,n−1)−ϕ(mpn,n−1)
// P2(m,n)=∑y<p≤√m(π(m/p)−π(p)+1)
//预处理降低递归复杂度
#define ll long long
ll f[340000], g[340000], n; // f为ϕ(n/i) g为ϕ(i)。
void init() {
    ll i, j, m;
    for (m = 1; m * m <= n; ++m) f[m] = n / m - 1;
    for (i = 1; i <= m; ++i) g[i] = i - 1;
    for (i = 2; i <= m; ++i) {
        if (g[i] == g[i - 1]) continue;
        for (j = 1; j <= min(m - 1, n / i / i); ++j) {
            if (i * j < m)
                f[j] -= f[i * j] - g[i - 1];
            else
                f[j] -= g[n / i / j] - g[i - 1];
        }
        for (j = m; j >= i * i; --j) g[j] -= g[j / i] - g[i - 1];
    }
}
int main() {
    while (cin >> n) {
        init();
        cout << f[1] << endl;
    }
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//模板2，代码量大，空间占用大，但是时间复杂度小，大概o（n^(2/3)） 两个板子跑1e11模板一用时1.2s模板2用时0.4s；
const int N = 5e6 + 2;
bool np[N];
int prime[N], pi[N];
int getprime() {
    int cnt = 0;
    np[0] = np[1] = true;
    pi[0] = pi[1] = 0;
    for (int i = 2; i < N; i++) {
        if (!np[i]) prime[++cnt] = i;
        pi[i] = cnt;
        for (int j = 1; j <= cnt && i * prime[j] < N; j++) {
            np[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    return cnt;
}
const int M = 7;
const int PM = 2 * 3 * 5 * 7 * 11 * 13 * 17;
int phi[PM + 1][M + 1], sz[M + 1];
void init() {
    getprime();
    sz[0] = 1;
    for (int i = 0; i <= PM; i++) phi[i][0] = i;
    for (int i = 1; i <= M; i++) {
        sz[i] = prime[i] * sz[i - 1];
        for (int j = 1; j <= PM; j++) phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
    }
}
int sqrt2(ll x) {
    ll r = (ll) sqrt(x - 0.1);
    while (r * r <= x) ++r;
    return int(r - 1);
}
int sqrt3(ll x) {
    ll r = (ll) cbrt(x - 0.1);
    while (r * r * r <= x) ++r;
    return int(r - 1);
}
ll get_phi(ll x, int s) {
    if (s == 0) return x;
    if (s <= M) return phi[x % sz[s]][s] + (x / sz[s]) * phi[sz[s]][s];
    if (x <= prime[s] * prime[s]) return pi[x] - s + 1;
    if (x <= prime[s] * prime[s] * prime[s] && x < N) {
        int s2x = pi[sqrt2(x)];
        ll ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
        for (int i = s + 1; i <= s2x; i++) ans += pi[x / prime[i]];
        return ans;
    }
    return get_phi(x, s - 1) - get_phi(x / prime[s], s - 1);
}
ll getpi(ll x) {
    if (x < N) return pi[x];
    ll ans = get_phi(x, pi[sqrt3(x)]) + pi[sqrt3(x)] - 1;
    for (int i = pi[sqrt3(x)] + 1, ed = pi[sqrt2(x)]; i <= ed; i++) ans -= getpi(x / prime[i]) - i + 1;
    return ans;
}
ll lehmer_pi(ll x) {
    if (x < N) return pi[x];
    int a = (int) lehmer_pi(sqrt2(sqrt2(x)));
    int b = (int) lehmer_pi(sqrt2(x));
    int c = (int) lehmer_pi(sqrt3(x));
    ll sum = get_phi(x, a) + (ll)(b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; i++) {
        ll w = x / prime[i];
        sum -= lehmer_pi(w);
        if (i > c) continue;
        ll lim = lehmer_pi(sqrt2(w));
        for (int j = i; j <= lim; j++) sum -= lehmer_pi(w / prime[j]) - (j - 1);
    }
    return sum;
}
//直接调用lehmer_pi函数即可
