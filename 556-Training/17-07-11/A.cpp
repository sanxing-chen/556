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
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PI acos(-1.0)
using namespace std;
const int MOD = 1e9 + 7;
const int N = 10050;
const int INF = 0x3f3f3f3f;
int n, m, x, y;
vector<int> v[N];
int color[N];
int vis[N];
void addedge(int i, int j) {
    v[i].push_back(j);
    v[j].push_back(i);
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> x >> y) {
        mems(color, 0);
        mems(vis, 0);
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            addedge(a, b);
        }
        for (int i = 1; i <= x; i++) {
            int xx;
            cin >> xx;
            color[xx] = 1;
        }
        for (int i = 1; i <= y; i++) {
            int yy;
            cin >> yy;
            color[yy] = 2;
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << color[i] << " ";
        // }
        // cout << endl;

        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if (color[i] != 0 && !vis[i]) {
                vis[i] = 1;
                queue<int> q;
                while (!q.empty()) {
                    q.pop();
                }
                q.push(i);
                while (!q.empty()) {
                    int x0 = q.front();
                    q.pop();
                    for (auto t : v[x0]) {
                        if (color[t] == 0) {
                            color[t] = 3 - color[x0];
                            vis[t] = 1;
                            q.push(t);
                            continue;
                        }
                        if (!vis[t] && color[t] != 0 && color[t] == 3 - color[x0]) {
                            vis[t] = 1;
                            q.push(t);
                            continue;
                        }
                        if (color[t] != 0 && color[t] != 3 - color[x0]) {
                            vis[t] = 1;
                            flag = 0;
                            goto exit;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (v[i].empty()) {
                    flag = 0;
                    goto exit;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                color[i] = 1;
                queue<int> q;
                while (!q.empty()) {
                    q.pop();
                }
                vis[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int x0 = q.front();
                    q.pop();
                    for (auto t : v[x0]) {
                        if (color[t] == 0) {
                            color[t] = 3 - color[x0];
                            vis[t] = 1;
                            q.push(t);
                            continue;
                        }
                        if (!vis[t] && color[t] != 0 && color[t] == 3 - color[x0]) {
                            vis[t] = 1;
                            q.push(t);
                            continue;
                        }
                        if (color[t] != 0 && color[t] != 3 - color[x0]) {
                            vis[t] = 1;
                            flag = 0;
                            goto exit;
                        }
                    }
                }
            }
        }
    exit:
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}