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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll dp[70];
ll fuck(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
int main() {
#ifdef FUCK
    freopen("1002.in", "r", stdin);
    freopen("my.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int t;
    ll k, n;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k == 1) {
            cout << fuck(n) << endl;
            continue;
        }
        dp[1] = 1;
        REP(i, 2, 66) {
            dp[i] = k * dp[i - 1] + 1;
        }
        ll ans = 0;
        int top;
        REP(i, 1, 66) {
            ans ^= dp[i];
            if (dp[i] > (n - 1) / k) {
                top = i;
                break;
            }
        }
        if (k % 2 == 0) ans = dp[top];

        ll rem = n - dp[top];
        if (rem & 1) ans ^= 1;
        ll temp = k;
        REP(i, 1, top + 1) {
            ll temp1 = rem / temp;
            ll temp2 = rem % temp;
            if (temp1 & 1) ans ^= dp[i] ^ (dp[i] + temp);
            if (temp2) ans ^= dp[i] ^ (dp[i] + temp2);
            temp *= k;
        }
        cout << ans << endl;
    }
    return 0;
}