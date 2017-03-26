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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
string mp[1005];
bool vis[1005][1005];
int _x[] = {-1, 0, 0, 1}, _y[] = {0, 1, -1, 0}, n, m;
bool cango(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y];
}
vector<pii> fuck;
void bfs(int x, int y) {
    int xx, yy, pre = 0;
    pii p;
    fuck.clear();
    queue<pii> q;
    q.push(pii(x, y));
    fuck.push_back(pii(x, y));
    if (mp[x][y] == '1') return;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            xx = x + _x[i], yy = y + _y[i];
            if (cango(xx, yy)) {
                vis[xx][yy] = true;
                if (mp[xx][yy] == '0') {
                    q.push(pii(xx, yy));
                    if (xx + yy > pre) {
                        fuck.clear();
                        pre = xx + yy;
                    }
                    if (xx + yy == pre) fuck.push_back(pii(xx, yy));
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    queue<pii> q;
    int cas;
    cin >> cas;
    while (cas--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> mp[i];
        }
        mems(vis, false);
        vis[0][0] = true;
        bfs(0, 0);
        pii p = *fuck.begin();
        string ans = mp[p.first][p.second] == '1' ? "1" : "";
        mems(vis, false);
        while (!q.empty()) q.pop();
        for (auto i : fuck) {
            q.push(i);
            vis[i.first][i.second] = true;
        }
        int pre = p.first + p.second;
        bool preFlag = ans == "" ? true : false;
        bool curFlag = false;
        while (!q.empty()) {
            pii qtop = q.front();
            if (qtop.first + qtop.second > pre) {
                pre = qtop.first + qtop.second;
                preFlag = curFlag;
                if (!preFlag)
                    ans += '1';
                else if (ans.size())
                    ans += '0';
                curFlag = false;
            }
            q.pop();
            if (preFlag && mp[qtop.first][qtop.second] == '1') continue;
            int x1 = qtop.first + 1, y1 = qtop.second, x2 = qtop.first, y2 = qtop.second + 1;
            if (cango(x1, y1) && cango(x2, y2)) {
                int sum = mp[x1][y1] + mp[x2][y2] - 2 * '0';
                if (sum == 0 || sum == 2) {
                    vis[x1][y1] = true, q.push(pii(x1, y1));
                    vis[x2][y2] = true, q.push(pii(x2, y2));
                    if (sum == 0) curFlag = true;
                } else {
                    if (mp[x1][y1] == '0')
                        vis[x1][y1] = true, q.push(pii(x1, y1));
                    else
                        vis[x2][y2] = true, q.push(pii(x2, y2));
                    curFlag = true;
                }
            } else {
                if (cango(x1, y1)) {
                    vis[x1][y1] = true, q.push(pii(x1, y1));
                    if (mp[x1][y1] == '0') curFlag = true;
                } else if (cango(x2, y2)) {
                    vis[x2][y2] = true, q.push(pii(x2, y2));
                    if (mp[x2][y2] == '0') curFlag = true;
                }
            }
        }
        cout << (ans == "" ? "0" : ans) << endl;
    }
    return 0;
}