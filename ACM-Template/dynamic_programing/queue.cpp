/*
 * HDU - 3530
 * 输出区间 m <= max - min <= k 的最大长度
 * 单调队列优化
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
const int maxn = 360000;
int ar[maxn];
int dp_min[maxn], dp_max[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    while (cin >> n >> m >> k) {
        REP(i, 0, n) {
            cin >> ar[i];
        }
        int min_front = 0, max_front = 0;
        int min_back = 0, max_back = 0;
        int ans = 0, now = -1;
        REP(i, 0, n) {
            while (min_front < min_back && ar[dp_min[min_back - 1]] > ar[i]) min_back--;
            dp_min[min_back++] = i;
            while (max_front < max_back && ar[dp_max[max_back - 1]] < ar[i]) max_back--;
            dp_max[max_back++] = i;
            while (min_front < min_back && max_front < max_back && ar[dp_max[max_front]] - ar[dp_min[min_front]] > k) {
                if (dp_max[max_front] < dp_min[min_front]) {
                    now = dp_max[max_front++];
                } else {
                    now = dp_min[min_front++];
                }
            }
            if (min_front < min_back && max_front < max_back && ar[dp_max[max_front]] - ar[dp_min[min_front]] >= m) {
                ans = max(ans, i - now);
            }
        }
        cout << ans << endl;
    }
    return 0;
}