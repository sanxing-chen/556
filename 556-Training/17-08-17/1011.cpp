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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int t;
ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b != 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll n, m;
int dp[2005][2005];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        dp[1][1] = m;
        for (ll i = 2; i <= n; i++) {
            for (ll j = 1; j < m; j++) {
                dp[i][j] = ((ll) dp[i - 1][j - 1] * (m - j + 1) % MOD + (ll) dp[i - 1][j] * j % MOD) % MOD;
            }
        }
        ll ans = 0;
        for (int i = 1; i < m; i++) {
            ans = (ans + (dp[n][i] * powmod(m - i, n, MOD) % MOD)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
