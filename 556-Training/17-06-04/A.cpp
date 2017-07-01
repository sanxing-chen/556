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
using namespace std;
const int maxn = 1111;
struct node {
    int u, v, next;
} edge[20005];
struct E {
    int w, id;
};
queue<int> q;
int head[1005], cnt, vis[1005];
void addedge(int u, int v) {
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].u = v;
    edge[cnt].v = u;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int n, m, x, y;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> x >> y) {
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            addedge(a, b);
        }
        for (int i = 0; i < x; i++) {
            int a;
            cin >> a;
            vis[a] = 1;
        }
        for (int i = 0; i < y; i++) {
            int a;
            cin >> a;
            vis[a] = 2;
        }
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            if (head[i] == -1 && vis[i] == 0) {
                flag = 0;
                // cout<<"1"<<endl;
                break;
            }
        }
        if (flag == 1) {
            queue<int> q;
            while (!q.empty()) { //对所有拥有已确定点的联通分枝进行染色
                q.pop();
            }
            for (int i = 1; i <= n; i++) {
                if (vis[i] != 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int xy = q.front();
                q.pop();
                for (int i = head[xy]; i != -1; i = edge[i].next) {
                    int yy = edge[i].v;
                    if (vis[yy] == 0) {
                        vis[yy] = 3 - vis[xy];
                        edge[i].u = yy;
                        q.push(yy);
                    } else if (vis[xy] == vis[yy]) {
                        flag = 0;
                        // cout<<"2"<<endl;
                        break;
                    }
                }
            }
            for (int i = 1; i <= n; i++) { //对所有尚未染色的联通分枝进行染色
                if (vis[i] == 0) {
                    queue<int> q1;
                    while (!q1.empty()) {
                        q1.pop();
                    }
                    vis[i] = 1;
                    q1.push(i);
                    while (!q1.empty()) {
                        int xx = q1.front();
                        q1.pop();
                        for (int j = head[xx]; j != -1; j = edge[j].next) {
                            int yyy = edge[j].v;
                            if (vis[yyy] == 0) {
                                vis[yyy] = 3 - vis[xx];
                                edge[j].u = yyy;
                                q1.push(yyy);
                            } else if (vis[yyy] == vis[xx]) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
