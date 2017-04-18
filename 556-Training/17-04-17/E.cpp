#include <algorithm>
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
    a[0] = 7;
    b[0] = 0;
    vis[0] = 1;
    while (T--) {
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
}