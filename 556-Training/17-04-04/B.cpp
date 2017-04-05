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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int c[1005];
int n;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            if (i != 1 && i != n) {
                sum += c[i];
            }
        }
        if (n == 1) {
            cout << c[1] << endl;
            continue;
        } else if (n == 2) {
            cout << ((c[1] + c[2]) / 2.0) << endl;
            continue;
        }
        double sum1 = 0;
        for (int i = 3; i <= n; i++) {
            sum1 += (i - 1) * (i - 2);
        }
        sum1 = sum1 / (n * (n - 1) * (n - 2));
        sum1 = sum * sum1;
        double sum2 = 0;
        for (int i = 2; i <= n; i++) {
            sum2 += (i - 1);
        }
        sum2 = sum2 / ((n - 1) * n);
        sum2 = sum2 * (c[1] + c[n]);
        double ans = sum1 + sum2;
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}