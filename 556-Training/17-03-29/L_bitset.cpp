#include <algorithm>
#include <bitset>
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
bitset<5005> L[26], R[26], N[26], dp[3], ndp[3];
char ans[100005];
int main() {
    freopen("1012.in", "r", stdin);
    freopen("L.out", "w", stdout);
    char str[100005], pat[5005];
    int cas, n, m;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);
        scanf("%s%s", str, pat);
        for (int i = 0; i < 26; i++) N[i].reset();
        for (int i = 0; i < m; i++) N[pat[i] - 'a'][i] = 1;
        for (int i = 0; i < 26; i++) {
            L[i] = N[i] << 1;
            R[i] = N[i] >> 1;
        }
        dp[0].reset(), dp[1].reset(), dp[2].reset();
        for (int i = 0; i < n; i++) ans[i] = '0';
        char pos;
        for (int i = 0; i < n; i++) {
            pos = str[i] - 'a';
            ndp[0] = dp[0] << 1 | dp[2] << 1;
            ndp[1] = R[pos] & ndp[0];
            ndp[0] = N[pos] & ndp[0];
            ndp[2] = L[pos] & dp[1] << 1;
            ndp[0][0] = N[pos][0], ndp[1][0] = R[pos][0];
            dp[0] = ndp[0], dp[1] = ndp[1], dp[2] = ndp[2];
            if (dp[0][m - 1] | dp[2][m - 1]) ans[i - m + 1] = '1';
        }
        ans[n] = '\0';
        printf("%s\n", ans);
    }
    showtime;
    return 0;
}