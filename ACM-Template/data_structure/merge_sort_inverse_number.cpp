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
const int N = 100005;
int a[N], b[N];
ll merge_sort(int l, int r) {
    if (l == r) return 0;
    ll cnt = 0;
    int m = (l + r) >> 1;
    cnt = merge_sort(l, m) + merge_sort(m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++], cnt += (m - i + 1);
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = b[i];
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    ll k;
    int n;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll sum = merge_sort(1, n);
        if (k < sum) {
            cout << sum - k << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}