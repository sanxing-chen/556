#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[10011][5][3];
const ll MOD = 100000007;
int main() {
    ios::sync_with_stdio(false);
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        ll ans = 0;

        memset(dp, 0, sizeof dp);
        int sz = str[0] - '0';
        bool fg = false;
        if (sz > 4) fg = true;
        REP(j, max(0, sz - 2), 3) {
            if (sz - j >= 0) {
                if (j == 1 && sz - j == 1)
                    dp[0][sz][j] += 4;
                else if (j == 1 || sz - j == 1)
                    dp[0][sz][j] += 2;
                else
                    dp[0][sz][j]++;
            }
        }
        // REP(j, 0, 5) {
        //     REP(k, 0, 3) {
        //         cout << dp[0][j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        REP(i, 1, str.size()) {
            REP(j, 0, 5) {
                REP(k, 0, 3) {
                    if (dp[i - 1][j][k]) {
                        sz = str[i] - '0' - j;
                        if (sz > 2 || sz < 0)
                            continue;
                        else {
                            int p = sz;
                            if (k + p < 5) {
                                if (p != 1)
                                    dp[i][k + p][p] += dp[i - 1][j][k];
                                else
                                    dp[i][k + p][p] += 2 * dp[i - 1][j][k] % MOD;
                            }
                            dp[i][k + p][p] %= MOD;
                        }
                    }
                }
            }
        }
        // REP(j, 0, 5) {
        //     REP(k, 0, 3) {
        //         cout << dp[str.size() - 1][j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if (fg)
            cout << 0 << endl;
        else {
            REP(j, 0, min(str.back() - '0', 2) + 1) {
                ans = (ans + dp[str.size() - 1][j][0]) % MOD;
            }
            cout << ans << endl;
        }
    }
}
