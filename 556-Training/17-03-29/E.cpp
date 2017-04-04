#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define eps 1e7
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct point {
    long long x, y;
} p[10005];
bool cmp(point x, point y) {
    if (x.x == y.x)
        return x.y < y.y;
    else
        return x.x < y.x;
}
long long x, y, T, n, k, sum, ans;
int a[2001][2001];
inline ll readT() {
    char c;
    ll ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
ll PowerMod(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
int main() {
    freopen("1005.in", "r", stdin);
    // freopen("E.out", "w", stdout);
    cin >> T;
    map<pii, ll> mp;
    while (T--) {
        n = readT();
        ans = 0;
        for (int i = 1; i <= n; i++) {
            x = readT();
            y = readT();
            p[i].x = x;
            p[i].y = y;
        }
        sort(p + 1, p + 1 + n, cmp);
        ll g, cnt, x, y;
        pii temp;
        for (int i = 1; i < n; i++) {
            mp.clear();
            cnt = 0;
            for (int j = i + 1; j <= n; j++) {
                if (p[i].x == p[j].x && p[i].y == p[j].y) {
                    cnt++;
                    continue;
                }
                x = p[i].x - p[j].x, y = p[i].y - p[j].y;
                g = __gcd(x, y);
                x /= g, y /= g;
                mp[pii(x, y)]++;
            }
            cnt = PowerMod(2, cnt, MOD);
            ans = (ans + cnt - 1) % MOD;
            for (auto i : mp) {
                ans = (ans + cnt * (PowerMod(2, i.second, MOD) - 1)) % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}