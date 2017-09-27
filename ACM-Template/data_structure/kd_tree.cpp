// kd-tree,虽然不是曼哈顿距离。但是还是能够从曼哈顿距离里面得到启发的。

// 本来的估价函数的原则是

// 如果在矩形内就返回0.这点不变。

// 然后在矩形外就返回到这个矩形的最小曼哈顿距离。现在改成欧几里得距离就可以了。

// 然后返回这个距离作为估价函数。

// 取估价函数较小的那个方向更新解就可以了。

// 前k小的话可以加一个队列维护。因为k最大为10，所以没必要写二分。

// 具体的看代码吧。

// 着重看一下估价函数就好。

// //数据范围实际上是可以不用定义long long的。但是保险起见。

// //k维的并没有什么可怕的。。就是for 0->1变成for 0->k-1

// //然后要注意多个维的点的输出最后一个维的坐标后面不能多空格。
/*
 最小曼哈顿
for(int i=0;i<k;i++){
            ret+=max(0,data[rt].mn[i]-p[i])+max(0,p[i]-data[rt].mx[i]);
        }
最大曼哈顿
for(int i=0;i<k;i++){
            ret+=max(abs(data[rt].mn[i]-p[i]),abs(p[i]-data[rt].mx[i]));
        }
最小欧几里得
       for(int i=0;i<k;i++){
            ret+=Sqrt2(max(max(data[rt].mn[i]-p[i],0),max(p[i]-data[rt].mx[i],0)));
        }
最大欧几里得          //取负取最小
       for(int i=0;i<k;i++){
            ret+=max(Sqrt2(data[rt].mn[i]-p[i]),Sqrt2(p[i]-data[rt].mx[i]));
        }
        O(log^2n)构造
        O(log n) 插入 删除
        O(n^(1-1/k)+m) m为每次要搜索的最近点的个数
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

#define N 50005

#define lson rt << 1
#define rson rt << 1 | 1
#define Pair pair<long long, Node>
#define Sqrt2(x) (x) * (x)
typedef long long ll;
int n, k, idx;

struct Node {
    int feature[5]; //定义属性数组
    bool operator<(const Node &u) const {
        return feature[idx] < u.feature[idx];
    }
    int id; //出现顺序
} _data[N]; //_data[]数组代表输入的数据

priority_queue<Pair> Q; //队列Q用于存放离p最近的m个数据

class KDTree {
  public:
    void Build(int, int, int, int);  //建树
    void Query(Node, int, int, int); //查询

  private:
    Node data[4 * N]; // data[]数组代表K-D树的所有节点数据
    int flag[4 * N];  //用于标记某个节点是否存在，1表示存在，-1表示不存在
} kd;

//建树步骤，参数dept代表树的深度
void KDTree::Build(int l, int r, int rt, int dept) {
    if (l > r) return;
    flag[rt] = 1;                 //表示编号为rt的节点存在
    flag[lson] = flag[rson] = -1; //当前节点的孩子暂时标记不存在
    idx = dept % k;               //按照编号为idx的属性进行划分
    int mid = (l + r) >> 1;
    nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
    data[rt] = _data[mid];
    Build(l, mid - 1, lson, dept + 1); //递归左子树
    Build(mid + 1, r, rson, dept + 1); //递归右子树
}

//查询函数，寻找离p最近的m个特征属性
void KDTree::Query(Node p, int m, int rt, int dept) {
    if (flag[rt] == -1) return; //不存在的节点不遍历
    Pair cur(0, data[rt]);      //获取当前节点的数据和到p的距离
    for (int i = 0; i < k; i++)
        cur.first += (ll) Sqrt2((ll) cur.second.feature[i] - (ll) p.feature[i]); //估计距离 容易爆
    int dim = dept % k; //跟建树一样，这样能保证相同节点的dim值不变 。 只需要使用用到的维度
    bool fg = 0;        //用于标记是否需要遍历右子树
    int x = lson;
    int y = rson;
    if (p.feature[dim] >= data[rt].feature[dim]) //数据p的第dim个特征值大于等于当前的数据，则需要进入右子树
        swap(x, y);
    if (~flag[x]) Query(p, m, x, dept + 1); //如果节点x存在，则进入子树继续遍历

    //以下是回溯过程，维护一个优先队列
    if (Q.size() < m) //如果队列没有满，则继续放入     //点使用限制
    {
        Q.push(cur);
        fg = 1;
    } else {
        if (cur.first < Q.top().first) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据 。／／点使用限制
        {
            Q.pop();
            Q.push(cur);
        }
        if ((ll) Sqrt2((ll) p.feature[dim] - (ll) data[rt].feature[dim]) < Q.top().first) {
            fg = 1;
        }
    }
    if (~flag[y] && fg) Query(p, m, y, dept + 1);
}

//输出结果
void Print(Node data) {
    for (int i = 0; i < k; i++) printf("%d%c", data.feature[i], i == k - 1 ? '\n' : ' ');
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) { // n个点 。 k维度
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++) scanf("%d", &_data[i].feature[j]);
        kd.Build(0, n - 1, 1, 0);
        int t, m;
        scanf("%d", &t);
        while (t--) { // t个询问
            Node p;
            for (int i = 0; i < k; i++) scanf("%d", &p.feature[i]);
            scanf("%d", &m);            //求第1-m临近点
            while (!Q.empty()) Q.pop(); //事先需要清空优先队列
            kd.Query(p, m, 1, 0);
            printf("the closest %d points are:\n", m);
            Node tmp[25];
            for (int i = 0; !Q.empty(); i++) {
                tmp[i] = Q.top().second;
                Q.pop();
            }
            for (int i = m - 1; i >= 0; i--) Print(tmp[i]);
        }
    }
    return 0;
}

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define Pair pair<long long, Node>
#define ll long long
#define inf 1000000000
#define Sqrt2(x) (x) * (x)
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m, root, idx, k;
struct Node {
    int fea[7], mn[7], mx[7], l, r;
    int &operator[](int x) {
        return fea[x];
    }
    Node(int x = 0, int y = 0) {
        l = 0, r = 0;
        fea[0] = x, fea[1] = y;
    }
} _data[200010];

bool operator<(Node a, Node b) {
    return a[idx] < b[idx];
}
priority_queue<Pair> Q;
inline ll dis(Node a, Node b) {
    ll tmp = 0;
    for (int i = 0; i < k; i++) tmp += Sqrt2(a[i] - b[i]);
    return tmp;
}
struct kdtree {
    int ans;
    Node data[200010], T;
    void update(int rt) {
        Node l = data[data[rt].l], r = data[data[rt].r];
        for (int i = 0; i < k; i++) {
            if (data[rt].l)
                data[rt].mn[i] = min(data[rt].mn[i], l.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], l.mx[i]);
            if (data[rt].r)
                data[rt].mn[i] = min(data[rt].mn[i], r.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], r.mx[i]);
        }
    }
    int build(int l, int r, int dep) {
        // idx = dep % k;
        idx = dep % k;
        int mid = (l + r) >> 1;
        nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
        data[mid] = _data[mid];
        for (int i = 0; i < k; i++) data[mid].mn[i] = data[mid].mx[i] = data[mid][i];
        if (l < mid) data[mid].l = build(l, mid - 1, idx + 1);
        if (r > mid) data[mid].r = build(mid + 1, r, idx + 1);
        update(mid);
        return mid;
    }
    ll get(int rt, Node p) {
        ll tmp = 0;
        for (int i = 0; i < k; i++) tmp += Sqrt2(max(p[i] - data[rt].mx[i], 0) + max(data[rt].mn[i] - p[i], 0));
        return tmp;
    }
    void insert(int rt, int dep) {
        // idx = dep % k;
        if (T[dep] >= data[rt][dep]) {
            if (data[rt].r)
                insert(data[rt].r, dep ^ 1);
            else {
                data[rt].r = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        } else {
            if (data[rt].l)
                insert(data[rt].l, dep ^ 1);
            else {
                data[rt].l = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        }
        update(rt);
    }
    void query(int rt) {
        int d, dl = inf, dr = inf;
        Pair cur(0, data[rt]); //获取当前节点的数据和到p的距离
        for (int i = 0; i < k; i++) cur.first += (ll) Sqrt2((ll) cur.second.fea[i] - (ll) T.fea[i]); //估计距离 容易爆
        //  cur.first = cur.first;
        if (Q.size() < m) //如果队列没有满，则继续放入     //点使用限制
        {
            Q.push(cur);
        } else {
            if (cur.first < Q.top().first) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据 。／／点使用限制
            {
                Q.pop();
                Q.push(cur);
            }
        }
        if (data[rt].l) dl = get(data[rt].l, T);
        if (data[rt].r) dr = get(data[rt].r, T);
        if (dl < dr) {
            if (dl < Q.top().first || Q.size() < m) query(data[rt].l);
            if (dr < Q.top().first || Q.size() < m) query(data[rt].r);
        } else {
            if (dr < Q.top().first || Q.size() < m) query(data[rt].r);
            if (dl < Q.top().first || Q.size() < m) query(data[rt].l);
        }
    }
    int query(Node p) {
        ans = inf;
        T = p;
        query(root);
        return ans;
    }
    void insert(Node p) {
        T = p;
        insert(root, 0);
    }
    void init() {
        memset(_data, 0, sizeof _data);
        memset(data, 0, sizeof data);
    }
} kd;
void Print(Node data) {
    for (int i = 0; i < k; i++) printf("%d%c", data.fea[i], i == k - 1 ? '\n' : ' ');
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        kd.init();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++) {
                _data[i].fea[j] = read();
            }
        int T;
        T = read();
        root = kd.build(1, n, 0);
        while (T--) {
            int x;
            int y;
            Node p;
            for (int i = 0; i < k; i++) {
                p.fea[i] = read();
            }
            scanf("%d", &m);
            while (!Q.empty()) Q.pop(); //事先需要清空优先队列
            kd.query(p);
            printf("the closest %d points are:\n", m);
            Node tmp[25];
            for (int i = 0; !Q.empty(); i++) {
                tmp[i] = Q.top().second;
                Q.pop();
            }
            for (int i = m - 1; i >= 0; i--) Print(tmp[i]);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x7fffffff
using namespace std;
int n, m, root, cmpd;
struct data {
    long long l, r, d[2], mx[2], mn[2], sum, w; // sum:以此为根节点数目和  w:节点上数字
    data() {}
    data(int a, int b, int val) {
        l = r = 0;
        d[0] = mx[0] = mn[0] = a;
        d[1] = mx[1] = mn[1] = b;
        w = sum = val;
    }
} tr[maxn];
void update(int x) {
    int l = tr[x].l, r = tr[x].r;
    if (l) // 维护以此为根的子树各个维度范围与节点数目和
    {
        tr[x].mx[0] = max(tr[x].mx[0], tr[l].mx[0]);
        tr[x].mn[0] = min(tr[x].mn[0], tr[l].mn[0]);
        tr[x].mx[1] = max(tr[x].mx[1], tr[l].mx[1]);
        tr[x].mn[1] = min(tr[x].mn[1], tr[l].mn[1]);
        tr[x].sum += tr[l].sum;
    }
    if (r) {
        tr[x].mx[0] = max(tr[x].mx[0], tr[r].mx[0]);
        tr[x].mn[0] = min(tr[x].mn[0], tr[r].mn[0]);
        tr[x].mx[1] = max(tr[x].mx[1], tr[r].mx[1]);
        tr[x].mn[1] = min(tr[x].mn[1], tr[r].mn[1]);
        tr[x].sum += tr[r].sum;
    }
}
int cmp(data a, data b) {
    if (a.d[cmpd] == b.d[cmpd]) {
        return a.d[(cmpd + 1) % 2] < b.d[(cmpd + 1) % 2];
    }
    return a.d[cmpd] < b.d[cmpd];
}
int build(int l, int r, int d) {
    int mid = (l + r) >> 1;
    cmpd = d;
    //不对整体排序，只求第n小的元素并放在其位置上
    nth_element(tr + l, tr + mid, tr + r + 1, cmp);
    tr[mid].mx[0] = tr[mid].mn[0] = tr[mid].d[0];
    tr[mid].mx[1] = tr[mid].mn[1] = tr[mid].d[1];
    tr[mid].sum = tr[mid].w;
    tr[mid].l = 0;
    tr[mid].r = 0;
    if (l < mid) {
        tr[mid].l = build(l, mid - 1, (d + 1) % 2);
    }
    if (r > mid) {
        tr[mid].r = build(mid + 1, r, (d + 1) % 2);
    }
    update(mid);
    return mid;
}
void kdinsert(int now) {
    if (now == root) {
        return;
    }
    int D, p;
    D = 0;
    p = root;
    while (true) {
        //插入到P中，维护信息
        if (tr[now].mx[0] > tr[p].mx[0]) {
            tr[p].mx[0] = tr[now].mx[0];
        }
        if (tr[now].mx[1] > tr[p].mx[1]) {
            tr[p].mx[1] = tr[now].mx[1];
        }
        if (tr[now].mn[0] < tr[p].mn[0]) {
            tr[p].mn[0] = tr[now].mn[0];
        }
        if (tr[now].mn[1] < tr[p].mn[1]) {
            tr[p].mn[1] = tr[now].mn[1];
        }
        tr[p].sum += tr[now].sum;
        if (tr[p].d[0] == tr[now].d[0] && tr[p].d[1] == tr[now].d[1]) //相等时只更新不插入
        {
            tr[p].w += tr[now].w;
            m--;
            return;
        }
        if (tr[now].d[D] >= tr[p].d[D]) {
            if (tr[p].r == 0) {
                tr[p].r = now;
                return;
            } else {
                p = tr[p].r;
            }
        } else {
            if (tr[p].l == 0) {
                tr[p].l = now;
                return;
            } else {
                p = tr[p].l;
            }
        }
        D = (D + 1) % 2;
    }
}
long long query(int now, int x1, int y1, int x2, int y2) {
    // 当前节点范围与查询矩形不相交
    if (!now || tr[now].mx[0] < x1 || tr[now].mn[0] > x2 || tr[now].mx[1] < y1 || tr[now].mn[1] > y2) {
        return 0;
    }
    // 当前节点范围包含查询矩形
    if (tr[now].mx[0] <= x2 && tr[now].mn[0] >= x1 && tr[now].mx[1] <= y2 && tr[now].mn[1] >= y1) {
        return tr[now].sum;
    }
    long long ret = 0;
    // 查询矩形包含当前节点
    if (tr[now].d[0] >= x1 && tr[now].d[0] <= x2 && tr[now].d[1] >= y1 && tr[now].d[1] <= y2) {
        ret += tr[now].w;
    }
    ret += query(tr[now].l, x1, y1, x2, y2) + query(tr[now].r, x1, y1, x2, y2);
    return ret;
}
int main() {
    int t;
    while (~scanf("%d", &n)) {
        long long kk = 0;
        int op;
        m = 0;
        int mod = 10000;
        root = 1;
        while (n--) {
            int x, y, z;
            scanf("%d %d %d", &z, &x, &y);
            tr[++m] = data(x, y, z);
        }
        root = build(1, m, 0);
        scanf("%d", &op);
        for (int i = 0; i < op; i++) {
            long long x1, y1, z1, x2, y2, z2;
            scanf("%lld %lld %lld %lld", &x1, &x2, &y1, &y2);
            x1 += kk, x2 -= kk;
            y1 += kk, y2 -= kk;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            long long ans = query(root, x1, y1, x2, y2);
            printf("%lld\n", ans);
            kk = ans;
        }
    }
    return 0;
}