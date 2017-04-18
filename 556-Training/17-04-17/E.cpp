#include <algorithm>
<<<<<<< HEAD
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
=======
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int vis[100];
ll x, y;
ll Cal(ll a, ll b, ll p) {
    return (a - b) / p;
}
ll qpow(ll a, ll b, ll p) {
    ll t = 1;
    for (a %= p; b; b >>= 1ll, a = a * a % p)
        if (b & (1ll)) t = t * a % p;
    return t;
}
ll a[100], b[100], n, k, T;
ll CRT1() {
    ll ans = 0, P = 1;
    for (int i = 0; i <= n; i++)
        if (vis[i]) P *= a[i];
    for (int i = 0; i <= n; i++)
        if (vis[i]) ans = (ans + (P / a[i]) * qpow(P / a[i], a[i] - 2, a[i]) % P * b[i] % P) % P;
    while (ans < 0) ans += P;
    return Cal(y + P, ans, P) - Cal(x - 1 + P, ans, P);
}
int main() {
    ios::sync_with_stdio(false);
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int cas;
    cin >> cas;
    T = cas;
>>>>>>> 775f43786008c5fe0025b11ff69edba728de591f
    a[0] = 7;
    b[0] = 0;
    vis[0] = 1;
    while (T--) {
<<<<<<< HEAD
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
=======
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            vis[i] = 0;
        }
        ll ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0, U = i;
            for (int j = 1; j <= n; j++) {
                vis[j] = U & 1, U >>= 1, cnt += vis[j];
            }
            if (cnt & 1)
                ans -= 1ll * CRT1();
            else
                ans += 1ll * CRT1();
        }
        cout << "Case #" << cas - T << ": " << ans << endl;
    }
>>>>>>> 775f43786008c5fe0025b11ff69edba728de591f
}