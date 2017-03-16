#include <algorithm>
#include <climits>
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
int n, m;
int s[30], t[30], off[10], on[10], num[10];
bool vis[30];
int dfs(int k) {
    int ans = 0;
    if (k == m + 1) {
        return 1;
    }
    if (off[s[k]] < num[s[k]] / 2 && off[t[k]] < num[t[k]] / 2) {
        off[s[k]]++;
        off[t[k]]++;
        ans += dfs(k + 1);
        off[s[k]]--;
        off[t[k]]--;
    }
    if (on[s[k]] < num[s[k]] / 2 && on[t[k]] < num[t[k]] / 2) {
        on[s[k]]++;
        on[t[k]]++;
        ans += dfs(k + 1);
        on[s[k]]--;
        on[t[k]]--;
    }
    return ans;
}
int main() {
    int tt, x, y;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        int cnt = 1;
        mems(num, 0);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            s[cnt] = x;
            t[cnt++] = y;
            num[x]++, num[y]++;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (num[i] & 1 || num[i] == 0) {
                flag = false;
                break;
            }
        }
        mems(off, 0);
        mems(on, 0);
        off[s[1]]++, off[t[1]]++;
        if (flag)
            cout << 2 * dfs(2) << endl;
        else
            cout << 0 << endl;
    }
}