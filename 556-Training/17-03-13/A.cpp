#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MOD (ll)(1e9 + 7)
using namespace std;
vector<int> v[10005];
void pre() {
    for (int i = 1; i < 10005; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) v[i].push_back(j);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n, l[100005], r[100005], vis[10005], a[100005];
    pre();
    ll ans = 0;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int maxl, minr;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            maxl = 0;
            for (auto j : v[a[i]]) {
                maxl = max(maxl, vis[j]);
            }
            l[i] = maxl;
            vis[a[i]] = max(vis[a[i]], i);
        }
        for (int i = 0; i < 10005; i++) {
            vis[i] = n + 1;
        }
        for (int i = n; i >= 1; i--) {
            minr = n + 1;
            for (auto j : v[a[i]]) {
                minr = min(minr, vis[j]);
            }
            r[i] = minr;
            vis[a[i]] = min(vis[a[i]], i);
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            // cout << l[ << " " << r[i]i] << " " << r[i] << endl;
            ans = (ans + (i - l[i]) * (r[i] - i)) % MOD;
        }
        cout << ans << endl;
    }
}