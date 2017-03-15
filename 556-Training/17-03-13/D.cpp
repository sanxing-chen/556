#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <climits>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    int t, n, a[210], temp, base, sum;
    const int MID = 40000;
    ll dp[2][80001];
    cin >> t;
    while(t--) {
        cin >> n;
        base = 0, sum = 0;
        mems(dp[base], 0);
        dp[base][MID + 0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            base ^= 1;
            for (int j = 0; j <= temp; j++) {
                for (int k = -sum; k <= sum; k++) {
                    dp[base][MID + k + j] = (dp[base][MID + k + j] + dp[base ^ 1][MID + k] * (((temp - j) / 2) + 1)) % MOD; //A
                    if (j != 0) 
                    dp[base][MID + k - j] = (dp[base][MID + k - j] + dp[base ^ 1][MID + k] * (((temp - j) / 2) + 1)) % MOD; //B
                }
                cout << dp[base][MID] << endl;
            }
            sum += temp;
        }
        cout << dp[base][MID + 0] << endl;
    }
    return 0;
}