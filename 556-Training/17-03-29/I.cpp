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
int a[100000], m, n, x, y, sum, sum2, T, minn;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        sum = 0;
        sum2 = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            a[x] = y;
        }
        if (n > 2) {
            minn = a[n] != 0 ? a[n] : 0;
        }
        int i;
        for (i = n - 1; i > 2; i--) {
            if (a[i] == 0)
                a[i] = minn;
            else
                break;
        }
        for (int j = i - 1; j > 2; j--) {
            if (a[j] == 0) a[j] = a[j + 1];
        }
        for (i = 3; i <= n; i++) sum += a[i];
        if (a[2] == 0) a[2] = a[1] == 0 ? 100 : a[1];
        if (a[1] == 0) a[1] = 100;
        sum2 = a[1] + a[2];
        cout << sum2 / __gcd(sum2, sum2 + sum) << "/" << (sum + sum2) / (__gcd(sum2, sum2 + sum)) << "\n";
    }
    return 0;
}