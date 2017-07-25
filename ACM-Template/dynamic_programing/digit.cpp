#include <algorithm>
#include <bitset>
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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int dp[10][10];
int digit[10];
ll dfs(int pos, int pre, bool limit) {
    if (pos == -1) return 1;
    if (!limit && ~dp[pos][pre]) return dp[pos][pre];
    ll ans = 0;
    int to = limit ? digit[pos] : 9;
    REP(d, 0, to + 1) {
        if (d != 4 && !(pre == 6 && d == 2)) {
            ans += dfs(pos - 1, d, limit && d == to);
        }
    }
    return limit ? ans : dp[pos][pre] = ans;
}
ll solve(int x) {
    int cnt = 0;
    while (x) {
        digit[cnt++] = x % 10;
        x /= 10;
    }
    return dfs(cnt - 1, 0, true);
}
int main() {
    ios::sync_with_stdio(false);
    int l, r;
    memset(dp, -1, sizeof(dp));
    while (cin >> l >> r && l + r) cout << solve(r) - solve(l - 1) << endl;
}