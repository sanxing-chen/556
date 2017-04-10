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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int mx = 100000 + 10; //数组最大长度
ll n, a[mx], k;             //数组长度，数组内容

int st1[mx][30]; // DP数组 维护最小
int st2[mx][30]; // DP数组 维护最大
void initRMQ1() {
    for (int i = 0; i < n; i++) st1[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) //使用位运算加速
        for (int i = 0; i + (1 << j) - 1 < n; i++) st1[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
}
void initRMQ2() {
    for (int i = 0; i < n; i++) st2[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) //使用位运算加速
        for (int i = 0; i + (1 << j) - 1 < n; i++) st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
}

int RMQ1(int u, int v) {
    int k = (int) (log(v - u + 1.0) / log(2.0)); //类型转换优先级高，除法整体要加括号
    return min(st1[u][k], st1[v - (1 << k) + 1][k]);
}
int RMQ2(int u, int v) {
    int k = (int) (log(v - u + 1.0) / log(2.0)); //类型转换优先级高，除法整体要加括号
    return max(st2[u][k], st2[v - (1 << k) + 1][k]);
}
// void initRMQIndex() {
//     for (int i = 0; i < n; i++) st[i][0] = i;
//     for (int j = 1; (1 << j) <= n; j++)
//         for (int i = 0; i + (1 << j) - 1 < n; i++)
//             st[i][j] = a[st[i][j - 1]] < a[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j -
//             1];
// }

// int RMQIndex(int s, int v) //返回最小值的下标
// {
//     int k = int(log(v - s + 1.0) / log(2.0));
//     return a[st[s][k]] < a[st[v - (1 << k) + 1][k]] ? st[s][k] : st[v - (1 << k) + 1][k];
// }
ll cha(int l, int r) {
    ll maxx = RMQ2(l, r);
    ll minn = RMQ1(l, r);
    return maxx - minn;
}

int firstLess(int n, int l) {
    // n + 1 个数
    int low = l;
    int high = n - 1;
    int mid = l;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (k <= cha(l, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return (low - 1 >= 0) ? low - 1 : -1;
}
ll T, ans;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        // cout << "a";
        initRMQ1();
        initRMQ2();
        // cout << "b";
        ans = 0;
        int maxx, minn;
        for (int i = 0; i < n; i++) {
            int r = firstLess(n, i);
            // cout << r << " " << i << endl;
            ans += r - i + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}