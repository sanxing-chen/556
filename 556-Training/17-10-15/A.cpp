#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2100;
string str[2100];
vector<int> v1[2100], v2[N];
int n;
int num[N], topo[N];
queue<int> q;
bool toposort(vector<int> v[]) {
    memset(num, 0, sizeof num);
    REP(i, 1, n + 1) {
        REP(j, 0, v[i].size()) {
            num[v[i][j]]++;
        }
    }
    while (!q.empty()) q.pop();
    REP(i, 1, n + 1) {
        if (!num[i]) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto i : v[u]) {
            num[i]--;
            if (!num[i]) q.push(i);
        }
    }
    return !(cnt == n);
}
bool vis[N];
int fuck = 0;
bool dfs(int a, vector<int> v[]) {
    vis[a] = true;
    REP(i, 0, v[a].size()) {
        int b = v[a][i];
        REP(j, 0, v[b].size()) {
            int c = v[b][j];
            if (fuck && str[a - 1][c - 1] != 'P') {
                // cout << fuck << endl;
                // cout << a << " " << c << endl;
                return false;
            }
            if (!fuck && str[a - 1][c - 1] != 'Q') {
                // cout << fuck << endl;
                // cout << a << " " << c << endl;
                return false;
            }
        }
        if (!vis[b] && !dfs(b, v)) return false;
    }
    return true;
}
bool solve(vector<int> v[]) {
    bool fg = true;
    memset(vis, false, sizeof vis);
    memset(num, 0, sizeof num);
    REP(i, 1, n + 1) {
        REP(j, 0, v[i].size()) {
            num[v[i][j]]++;
        }
    }
    REP(i, 1, n + 1) {
        if (!num[i]) {
            if (!dfs(i, v)) fg = false;
        }
    }
    return fg;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 0, n) {
            cin >> str[i];
        }
        REP(i, 0, n + 1) v1[i].clear(), v2[i].clear();
        REP(i, 0, n + 1) {
            REP(j, 0, str[i].size()) {
                if (str[i][j] == 'P') {
                    v1[i + 1].push_back(j + 1);
                } else if (str[i][j] == 'Q') {
                    v2[i + 1].push_back(j + 1);
                }
            }
        }
        if (toposort(v1) || toposort(v2)) {
            cout << "N" << endl;
        } else {
            fuck = 1;
            bool fg1 = solve(v1);
            fuck = 0;
            bool fg2 = solve(v2);
            if (fg1 && fg2) {
                cout << "T" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}