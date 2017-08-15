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
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        m = min(m, n * (n - 1) / 2);
        ll ans = n * (n - 1) * n;
        if (m >= n - 1) {
            REP(i, 1, n) {
                ans -= 2 * ((n - 1) + (i - 1) * (n - 2));
            }
            m -= n - 1;
        } else {
            REP(i, 1, m + 1) {
                ans -= 2 * ((n - 1) + (i - 1) * (n - 2));
            }
            m = 0;
        }
        ans -= 2 * m;
        cout << ans << endl;
    }
    return 0;
}