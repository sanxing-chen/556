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
int sg[1 << 21];
bool mark[100];
void getsg(int pos) {
    mems(mark, false);
    for (int i = 19; i > 0; i--) {
        if ((1 << i) & pos) {
            for (int j = i - 1; j >= 0; j--) {
                if (!((1 << j) & pos)) {
                    mark[sg[pos ^ (1 << i) ^ (1 << j)]] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < (1 << 21); i++) {
        if (!mark[i]) {
            sg[pos] = i;
            break;
        }
    }
}
void fuck() {
    for (int i = 0; i < (1 << 20); i++) {
        getsg(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    int cas, n, m, sum, ans, temp, vis[30];
    fuck();
    cin >> cas;
    while (cas--) {
        cin >> n;
        ans = 0;
        while (n--) {
            cin >> m;
            sum = 0;
            mems(vis, 0);
            for (int i = 0; i < m; i++) {
                cin >> temp;
                vis[temp] = 1;
            }
            sum |= vis[1];
            for (int i = 2; i <= 20; i++) {
                sum <<= 1;
                sum |= vis[i];
            }
            ans ^= sg[sum];
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}