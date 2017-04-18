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
ll PowerMod(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
int f[100005];
vector<int> v;
int KMP(string s, string t) {
    int m = s.size(), cnt = 0;
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
    for (int i = 0, j = 0; t[i]; ++i) {
        while (j && t[i] != s[j]) j = f[j];
        j += (t[i] == s[j]);
        if (j == m) {
            cnt++;
            v.push_back(i - m + 1);
        }
    }
    return cnt;
}
ll dp[100005][2];
int main() {
    ios::sync_with_stdio(false);
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int cas;
    string str, pat;
    cin >> cas;
    for (int ca = 1; ca <= cas; ca++) {
        cin >> str >> pat;
        v.clear();
        cout << "Case #" << ca << ": ";
        KMP(pat, str);
        if (v.size() == 0) {
            cout << "1" << endl;
        } else if (v.size() == 1) {
            cout << "2" << endl;
        } else {
            dp[0][1] = dp[0][0] = 1;
            for (int i = 1; i < v.size(); i++) {
                int pos = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (v[j] + pat.size() <= v[i]) {
                        pos = j;
                        break;
                    }
                }
                if (~pos) {
                    dp[i][1] = (dp[pos][0] + dp[pos][1]) % MOD;
                    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                } else {
                    dp[i][1] = 1;
                    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                }
                // cout << dp[i][0] << " " << dp[i][1] << endl;
            }
            cout << (dp[v.size() - 1][0] + dp[v.size() - 1][1]) % MOD << endl;
        }
    }
    return 0;
}