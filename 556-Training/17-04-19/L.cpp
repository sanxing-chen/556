
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
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 60000;
struct node {
    int id, va;
} b[N];
int a[N], c[N];
int cnt1[N], cnt2[N], cnt3[N], cnt4[N], ro[N];
int n;
int cmp(node x, node y) {
    return x.va < y.va;
}
int cmp1(node x, node y) {
    return x.va > y.va;
}
int lowbit(int x) {
    return x & (-x);
}
void updata(int t, int value) {
    for (int i = t; i <= n; i += lowbit(i)) c[i] += value;
}
int sum(int x) {
    int temp = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) temp += c[i];
    return temp;
}
int main() {
#ifdef FF
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n) {
        ll sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b[i].va;
            ro[i] = b[i].va;
            b[i].id = i;
        }
        memset(c, 0, sizeof(c));
        stable_sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++) a[b[i].id] = i;
        for (int i = 1; i <= n; i++) {
            updata(a[i], 1);
            cnt1[i] = i - sum(a[i]);
            sum1 += cnt1[i];
        }
        memset(c, 0, sizeof(c));
        stable_sort(b + 1, b + n + 1, cmp1);
        for (int i = 1; i <= n; i++) a[b[i].id] = i;
        for (int i = 1; i <= n; i++) {
            updata(a[i], 1);
            cnt2[i] = i - sum(a[i]);
            sum2 += cnt2[i];
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << cnt1[i] << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << cnt2[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++) {
            b[i].va = ro[n - i + 1];
            b[i].id = i;
        }
        memset(c, 0, sizeof(c));
        stable_sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++) a[b[i].id] = i;
        for (int i = 1; i <= n; i++) {
            updata(a[i], 1);
            cnt3[i] = i - sum(a[i]);
        }
        memset(c, 0, sizeof(c));
        stable_sort(b + 1, b + n + 1, cmp1);
        for (int i = 1; i <= n; i++) a[b[i].id] = i;
        for (int i = 1; i <= n; i++) {
            updata(a[i], 1);
            cnt4[i] = i - sum(a[i]);
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << cnt3[n - i + 1] << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << cnt4[n - i + 1] << " ";
        // }
        // cout << endl;
        sum1 *= sum2;
        for (int i = 1; i <= n; i++) {
            sum1 -= cnt2[i] * cnt4[n - i + 1] + cnt1[i] * cnt3[n - i + 1] + cnt1[i] * cnt2[i] + cnt3[n - i + 1] * cnt4[n - i + 1];
        }
        cout << sum1 << endl;
    }
    return 0;
}