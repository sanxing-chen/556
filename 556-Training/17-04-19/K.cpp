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
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1005;
ll dp[N][N], a[N], b[N];
int main() {
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int n, m;
    ll ans = 0;
    while (cin >> n >> m) {
        mems(dp, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + MOD) % MOD;
                if (a[i] == b[j]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1) % MOD;
            }
        }
        cout << (dp[n][m] % MOD) << endl;
    }
    return 0;
}