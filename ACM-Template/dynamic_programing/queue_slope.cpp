/*
 * HDU - 3507
 * 斜率优化，单调队列维护凸包
 * 两个队列内分别保存最大和最小值的下标，不合条件时出队，每个元素出队次数 O(1) 整体复杂度 O(n)
 */
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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 600000;
ll ar[maxn], dp[maxn], sum[maxn];
int q[maxn];
ll n, m;
ll cost(int s, int t) {
    return dp[s] + pow(sum[t] - sum[s], 2) + m;
}
ll up(int l, int r) {
    return dp[r] - dp[l] + pow(sum[r], 2) - pow(sum[l], 2);
}
bool useless(int back, int now) {
    back--;
    return up(q[back - 1], now) * (sum[q[back]] - sum[q[back - 1]]) <= up(q[back - 1], q[back]) * (sum[now] - sum[q[back - 1]]);
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        sum[0] = dp[0] = 0;
        REP(i, 1, n + 1) {
            cin >> ar[i];
            sum[i] = sum[i - 1] + ar[i];
        }
        int front = 0, back = 0;
        q[back++] = 0;
        REP(i, 1, n + 1) {
            while (front + 1 < back && 2 * sum[i] * (sum[q[front + 1]] - sum[q[front]]) >= up(q[front], q[front + 1])) {
                front++;
            }
            dp[i] = cost(q[front], i);
            while (front + 1 < back && useless(back, i)) {
                back--;
            }
            q[back++] = i;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
