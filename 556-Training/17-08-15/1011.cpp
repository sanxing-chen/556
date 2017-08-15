#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
using namespace std;

typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 10005;
int a[10000005];
ll sum[100000005] = {0};
void stay() {
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    a[4] = 1;
    sum[1] = 1;
    sum[2] = 3;
    ll temp;
    int i = 3;
    while (1) {
        sum[i] += sum[i - 1] + a[i];
        if (sum[i] > 10000005) break;
        a[sum[i]] = (3 + ((i & 1) ? (-1) : 1)) / 2;
        a[sum[i] + 1] = (3 - ((i & 1) ? (-1) : 1)) / 2;
        i++;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    int t, n;
    cin >> t;
    stay();
    while (t--) {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}