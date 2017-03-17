#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define LL long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 800005;
struct BIT {
    ll a[N], n;
    void init(int i) {
        memset(a, 0, sizeof a);
        n = i;
    }
    inline int lowbit(int x) {
        return (x & -x);
    }
    void update(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) a[i] += v;
    }
    ll sum(int x) {
        ll res = 0;
        for (int i = x; i; i -= lowbit(i)) res += a[i];
        return res;
    }
} T;
int main() {
    ios::sync_with_stdio(false);
    ll k;
    int n;
    pii a[100005];
    int s[100005];
    while (cin >> n >> k) {
        T.init(n);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            s[a[i].second] = i;
        }
        for (int i = 1; i <= n; i++) {
            T.update(s[i], 1);
            sum += i - T.sum(s[i]);
        }
        if (k < sum) {
            cout << sum - k << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}