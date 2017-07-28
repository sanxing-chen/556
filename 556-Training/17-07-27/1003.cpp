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
const int maxn = 300000;
int ar[maxn], br[maxn];
int dp[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        ll ans = 0;
        REP(i, 1, n + 1) {
            cin >> ar[i];
        }
        REP(i, 1, n + 1) {
            cin >> br[i];
        }
        int temp = 0;
        PER(i, 1, n + 1) {
            temp = max(temp, ar[i] - i);
            dp[i] = temp;
        }
        sort(br + 1, br + n + 1);
        temp = 0;
        int add = 0;
        REP(i, 1, n + 1) {
            add = max(temp, dp[br[i]]);
            ans = (ans + add) % MOD;
            temp = max(temp, add - (i + n));
        }
        cout << ans << endl;
    }
    return 0;
}