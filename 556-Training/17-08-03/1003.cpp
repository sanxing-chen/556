#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n) -1; i >= a; --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int tot = 0;
#define N 1000100 // range to screen
int prime[N];
bool vis[N] = {true, true};
void screen() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot && (ll) i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int cnt[N];
ll mem[N];
int main() {
    ios::sync_with_stdio(false);
    screen();
    ll t, l, r, k, temp, s;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        ll ans = 0;
        int sz = r - l;
        REP(i, 0, sz + 1) cnt[i] = 1, mem[i] = i + l;
        REP(ii, 0, tot) {
            int i = prime[ii];
            if ((ll) i * i > r) break;
            if (l % i == 0)
                s = l;
            else
                s = l / i * i + i;
            for (; s <= r; s += i) {
                int o = 0, te = s - l;
                while (!(mem[te] % i)) {
                    mem[te] /= i;
                    o++;
                }
                cnt[te] = (ll) cnt[te] * (k * o + 1) % MOD;
            }
        }
        REP(i, 0, sz + 1) {
            ans = (ans + (mem[i] == 1 ? 1 : (k + 1)) * cnt[i]) % MOD;
        }
        cout << ans << endl;
    }
}