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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1ll << 50;
const int maxn = 201100;
struct node {
    int num;
    ll len;
    bool operator<(const node &a) const {
        return len > a.len; //优先队列强制设置为以len为关键词的小顶堆
    }
};

int u[maxn], v[maxn];
ll w[maxn];                 //依次表示每条道路上的起始点、终点和长度
ll dis[maxn], second[maxn]; //记录通往每一个路口的最短和次短距离
int first[maxn], nxt[maxn];
int n, m;

void Dijkstra() {
    priority_queue<node> q;
    for (int i = 1; i < n; i++) dis[i] = second[i] = INF;
    dis[0] = 0;      //源点的最短边可以初始化为0
    second[0] = INF; //但是源点的次短边必须初始化为INF，而不是0（否则会出错）
    node temp;
    temp.num = temp.len = 0;
    q.push(temp);
    while (!q.empty()) {
        node head = q.top();
        q.pop();
        if (head.len > second[head.num]) //对于该点的最短距离大于当前该点的次短距离，则当前该点已经取到最短和次短距离，不进行操作
            continue;
        int k = first[head.num];
        while (k != -1) {
            ll d = head.len + w[k]; //否则进行两次判断
            if (dis[v[k]] > d) //判断一：如果小于最短距离（把最短距离赋给次短距离，再把当前距离赋给最短距离）
            {
                swap(dis[v[k]], d); //实际上灵活运用下面一个if判断，只要把当前距离跟最短距离进行交换即可
                temp.len = dis[v[k]];
                temp.num = v[k];
                q.push(temp);
            }
            if (dis[v[k]] < d && second[v[k]] > d) //判断二：如果大于最短距离并小于次短距离 （把当前距离赋给次短距离）
            {
                second[v[k]] = d;
                temp.len = second[v[k]];
                temp.num = v[k];
                q.push(temp);
            }
            k = nxt[k]; //枚举每一条边
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(first, -1, sizeof(first));
        for (int i = 0; i < m; i++) {
            cin >> u[i] >> v[i] >> w[i];
            u[i]--;
            v[i]--;
            nxt[i] = first[u[i]];
            first[u[i]] = i;
            v[i + m] = u[i];
            u[i + m] = v[i];
            w[i + m] = w[i];
            nxt[i + m] = first[u[i + m]];
            first[u[i + m]] = i + m;
        }
        Dijkstra();
        cout << second[n - 1] << endl;
    }
    return 0;
}