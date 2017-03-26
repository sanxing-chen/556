#include <algorithm>
#include <climits>
#include <cmath>
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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int a[200000], b[200000], n, m, sum = 0, ans, maxx, pos, len, seq[200000];
int f[200000] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];
    }
    m = n;
    ans = 0;
    for (auto i : a) {
        pos = lower_bound(seq, seq + len, i) - seq; // 此处使用 lower_bound() 进行二分搜索
        seq[pos] = i;
        len = max(len, pos + 1); // 是否成为最大的元素使 LIS 增长，如无，则保留原来的长度
        f[i] = len;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << f[i] << " ";
    // }
    cout << len;
    return 0;
}