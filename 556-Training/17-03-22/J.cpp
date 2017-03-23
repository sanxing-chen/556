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
int r, c;
struct node {
    int x, y, s, far, up, down, left, right, exist, exist_t, bt;
} No[110];
int mp[105][105];
bool cango(int x, int y) {
    return x > 0 && y > 0 && x <= r && y <= c;
}
int _x[] = {0, 0, -1, 1};
int _y[] = {-1, 1, 0, 0};
void expo(int p, int t) {
    node &temp = No[p];
    temp.s = 0, temp.exist = 0, temp.exist_t = t, temp.bt = t;
    temp.up = temp.down = temp.left = temp.right = 1;
    temp.far = 0;
}
int main() {
    ios::sync_with_stdio(false);
    int n, T, x, y, s;

    while (cin >> r >> c >> n >> T) {
        mems(mp, 0);
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> s;
            mp[x][y] = i;
            No[i].x = x, No[i].y = y, No[i].s = s;
            No[i].up = No[i].down = No[i].left = No[i].right = 0;
            No[i].far = 0;
            No[i].bt = -1, No[i].exist_t = 0, No[i].exist = 1;
        }
        cin >> x >> y;
        No[n + 1].x = x, No[n + 1].y = y, No[n + 1].s = 0, No[n + 1].far = 0;
        expo(n + 1, 0);
        for (int t = 1; t <= T; t++) {
            for (int j = 1; j <= n + 1; j++) {
                node &temp = No[j];
                if (temp.exist || temp.bt == t) continue;
                temp.far++;
                int x, y;
                for (int i = 0; i < 4; i++) {
                    x = _x[i] * temp.far + temp.x, y = _y[i] * temp.far + temp.y;
                    bool flag = true;
                    if (cango(x, y) && mp[x][y] && No[mp[x][y]].exist) {
                        switch (i) {
                            case 0:
                                if (!temp.up) flag = false;
                                temp.up = 0;
                                break;
                            case 1:
                                if (!temp.down) flag = false;
                                temp.down = 0;
                                break;
                            case 2:
                                if (!temp.left) flag = false;
                                temp.left = 0;
                                break;
                            case 3:
                                if (!temp.right) flag = false;
                                temp.right = 0;
                                break;
                        }
                        if (!flag) continue;
                        No[mp[x][y]].s++;
                    }
                }
            }
            for (int i = 1; i <= n + 1; i++) {
                if (No[i].s > 4) expo(i, t);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (No[i].exist) {
                cout << 1 << " " << No[i].s << endl;
            } else {
                cout << 0 << " " << No[i].exist_t << endl;
            }
        }
    }
    return 0;
}
