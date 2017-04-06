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
const int MOD = 258280327;
const int INF = 0x3f3f3f3f;
ll dp[2][10];
int main() {
    ios::sync_with_stdio(false);
    int t, index, a, b, n, temp, sum, cnt;
    cin >> t;
    while (t--) {
        mems(dp, 0);
        index = sum = cnt = 0;
        cin >> n >> a >> b;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp == 9) {
                cnt++;
            }
            sum = (sum + temp) % 9;
            for (int j = 0; j < 9; j++) {
                dp[index][j] = 0;
            }
            dp[index][temp % 9]++;
            for (int j = 0; j < 9; j++) {
                dp[index][j] = (dp[index][j] + dp[!index][j]) % MOD;
                dp[index][(j + temp) % 9] = (dp[index][(j + temp) % 9] + dp[!index][j]) % MOD;
            }
            index = !index;
        }
        a %= 9, b %= 9;
        if (a == b && a == 0) dp[!index][a] = (dp[!index][a] + 1) % MOD;
        if (sum != (a + b) % 9)
            if (sum == a && b != 0) {
                cout << 1 << endl;
                continue;
            } else if (sum == b && a != 0) {
                cout << 1 << endl;
                continue;
            }
        if (sum == (a + b) % 9) {
            cout << max(dp[!index][a], dp[!index][b]) << endl;
        } else if (sum == a) {
            cout << dp[!index][a] << endl;
        } else if (sum == b) {
            cout << dp[!index][b] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}