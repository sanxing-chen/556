#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
LL a[20], b[20], l, r;
int T, n, Cas = 1, vis[20];
LL pow(LL a, LL b, LL p) {
    LL t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
LL Cal(LL r, LL l, LL m) {
    return (r - l) / m;
}
LL CRT(LL *a, LL *b, int n) {
    LL ans = 0, P = 1;
    for (int i = 0; i < n; i++)
        if (vis[i]) P *= a[i];
    for (int i = 0; i < n; i++)
        if (vis[i]) ans = (ans + (P / a[i]) * pow(P / a[i], a[i] - 2, a[i]) % P * b[i] % P) % P;
    while (ans < 0) ans += P;
    return Cal(r + P, ans, P) - Cal(l - 1 + P, ans, P);
}
int main() {
    scanf("%d", &T);
    a[0] = 7;
    b[0] = 0;
    vis[0] = 1;
    while (T--) {
        scanf("%d%lld%lld", &n, &l, &r);
        for (int i = 1; i <= n; i++) scanf("%lld%lld", a + i, b + i), vis[i] = 0;
        LL ans = 0;
        int all = 1 << n;
        for (int i = 0; i < all; i++) {
            int U = i, cnt = 0;
            for (int j = 1; j <= n; j++) vis[j] = U & 1, U >>= 1, cnt += vis[j];
            cnt = cnt & 1 ? -1 : 1;
            ans += 1LL * cnt * CRT(a, b, n + 1);
        }
        printf("Case #%d: %lld\n", Cas++, ans);
    }
    return 0;
}