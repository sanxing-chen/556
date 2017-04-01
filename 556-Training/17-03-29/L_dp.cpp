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
#define showtime printf("time = %.15f\n", clock() / (double) CLOCKS_PER_SEC)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
bool dp[2][5001][3], flag, can;
int main() {
    // freopen("1012.in", "r", stdin);
    // freopen("L.out", "w", stdout);

    ios::sync_with_stdio(false);
    string str, pat;
    int cas, n, m;
    cin >> cas;
    while (cas--) {
        cin >> n >> m;
        cin >> str >> pat;
        mems(dp, false);
        bool index = 0;
        for (int i = 0; i < n; i++) {
            dp[index][0][0] = str[i] == pat[0];
            dp[index][0][1] = m > 1 && str[i] == pat[1];
            dp[index][0][2] = false;
            for (int j = 1; j < m && j <= i; j++) {
                dp[index][j][0] = str[i] == pat[j] && (dp[!index][j - 1][0] || dp[!index][j - 1][2]);
                dp[index][j][1] = j < m - 1 && (dp[!index][j - 1][0] || dp[!index][j - 1][2]) && str[i] == pat[j + 1];
                dp[index][j][2] = dp[!index][j - 1][1] && str[i] == pat[j - 1];
            }
            if (i >= m - 1) cout << (dp[index][m - 1][0] || dp[index][m - 1][2]);
            index = !index;
        }
        // for (int i = m - 1; i < n; i++) {
        //     cout << (dp[i][m - 1][0] || dp[i][m - 1][2]);
        // }
        for (int i = 0; i < m - 1; i++) cout << 0;
        cout << endl;
    }
    return 0;
}