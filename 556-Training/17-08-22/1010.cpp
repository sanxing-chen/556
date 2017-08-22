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
#include <regex>
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
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
bool dp[2600][2600];
bool vis[2600][2600];
char a[2600], b[2600];
int main() {
    int t;
    scanf("%d", &t);
    a[0] = b[0] = '^';
    gets(a + 1);
    while (t--) {
        gets(a + 1);
        gets(b + 1);
        int n = strlen(a) - 1, m = strlen(b) - 1;
        mems(dp, false);
        mems(vis, false);
        dp[0][0] = true;
        REP(i, 0, n + 1) {
            REP(j, 1, m + 1) {
                if (a[i] == b[j]) dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                if (b[j] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                } else if (b[j] == '*') {
                    dp[i][j] = dp[i][j] || dp[i][j - 1] || dp[i][j - 2];
                    if (dp[i - 1][j - 1] && !vis[i - 1][j - 1]) {
                        vis[i - 1][j - 1] = true;
                        REP(k, 0, n + 1 - i) {
                            if (a[i + k] == a[i + k - 1]) {
                                dp[i + k][j] = 1;
                                vis[i + k][j - 1] = 1;
                            } else
                                break;
                        }
                    }
                }
            }
        }
        dp[n][m] ? puts("yes") : puts("no");
    }
    return 0;
}