#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#define maxn 100005
using namespace std;
int b[maxn], t[maxn], n, m, size, v[maxn], tot = 0;
struct chairtree {
    int l, r, size;
} a[maxn * 30];
int Build(int l, int r) {
    int root = ++tot;
    a[root].size = 0;
    if (l == r) return root;
    int m = (l + r) >> 1;
    a[root].l = Build(l, m);
    a[root].r = Build(m + 1, r);
    return root;
}
int Update(int root, int x) {
    int now = ++tot;
    int tmp = now;
    a[tot].size = a[root].size + 1;
    int l = 1, r = size;
    while (l < r) {
        int m = (l + r) >> 1;
        if (x <= m) {
            a[now].l = ++tot;
            a[now].r = a[root].r; //充分利用原来相同的结点
            root = a[root].l;
            now = tot;
            r = m;
        } else {
            a[now].l = a[root].l;
            a[now].r = ++tot;
            root = a[root].r;
            now = tot;
            l = m + 1;
        }
        a[now].size = a[root].size + 1;
    }
    return tmp;
}
int Ask(int lx, int rx, int k) {
    int l = 1, r = size;
    while (l < r) {
        int m = (l + r) >> 1;
        if (a[a[rx].l].size - a[a[lx].l].size >= k) {
            r = m;
            lx = a[lx].l;
            rx = a[rx].l;
        } else {
            l = m + 1;
            k -= a[a[rx].l].size - a[a[lx].l].size;
            lx = a[lx].r;
            rx = a[rx].r;
        }
    }
    return l;
}
void Hash1() {
    sort(b + 1, b + 1 + n);
    size = unique(b + 1, b + 1 + n) - b - 1; //求不相同的数有几个
}
int Hash(int x) {
    return lower_bound(b + 1, b + 1 + size, x) - b; //找到x在排好序的序列中出现的位置，即离散化后的值
}
int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]), b[i] = v[i];
        Hash1();
        t[0] = Build(1, size);
        for (int i = 1; i <= n; i++) //建n棵线段树
            t[i] = Update(t[i - 1], Hash(v[i]));
        while (m--) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", b[Ask(t[l - 1], t[r], k)]);
        }
    }
    return 0;
}

//带区间修改:前缀和用树状数组维护：
int use[maxn * 10], n, m, size, tot = 0, all = 0, h[maxn * 10], v[maxn * 10], t[maxn * 10];
struct chairtree {
    int l, r, size;
} a[maxn * 300];
struct question {
    int l, r, k;
} q[maxn];
int lowbit(int x) {
    return x & (-x);
}
void Hash1() {
    sort(h + 1, h + 1 + all);
    size = unique(h + 1, h + 1 + all) - h - 1;
}
int Hash(int x) {
    return lower_bound(h + 1, h + 1 + size, x) - h;
}
int Build(int l, int r) {
    int now = ++tot;
    a[now].size = 0;
    if (l == r) return now;
    int m = (l + r) >> 1;
    a[now].l = Build(l, m);
    a[now].r = Build(m + 1, r);
    return now;
}
int Update(int root, int p, int val) {
    int now = ++tot, tmp = now;
    int l = 1, r = size;
    a[now].size = a[root].size + val;
    while (l < r) {
        int m = (l + r) >> 1;
        if (p <= m) {
            a[now].l = ++tot;
            a[now].r = a[root].r;
            root = a[root].l;
            now = a[now].l;
            r = m;
        } else {
            a[now].l = a[root].l;
            a[now].r = ++tot;
            root = a[root].r;
            now = a[now].r;
            l = m + 1;
        }
        a[now].size = a[root].size + val;
    }
    return tmp;
}
void Add(int x, int p, int val) {
    for (int i = x; i <= n; i += lowbit(i)) //树状数组只需修改logn个
        t[i] = Update(t[i], p, val);
}
int Getsum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += a[a[use[i]].l].size;
    return ans;
}
int Query(int lx, int rx, int k) {
    int l = 1, r = size;
    for (int i = lx - 1; i; i -= lowbit(i)) use[i] = t[i];
    for (int i = rx; i; i -= lowbit(i)) use[i] = t[i];
    while (l < r) {
        int m = (l + r) >> 1;
        int tmp = Getsum(rx) - Getsum(lx - 1);
        if (tmp >= k) {
            for (int i = lx - 1; i; i -= lowbit(i)) use[i] = a[use[i]].l;
            for (int i = rx; i; i -= lowbit(i)) use[i] = a[use[i]].l;
            r = m;
        } else {
            for (int i = lx - 1; i; i -= lowbit(i)) use[i] = a[use[i]].r;
            for (int i = rx; i; i -= lowbit(i)) use[i] = a[use[i]].r;
            k -= tmp;
            l = m + 1;
        }
    }
    return l;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]), h[i] = v[i];
    all = n;
    for (int i = 1; i <= m; i++) {
        char str[10];
        int l, r, k;
        scanf("%s", str);
        if (str[0] == 'Q') {
            scanf("%d%d%d", &l, &r, &k);
            q[i].l = l, q[i].r = r, q[i].k = k;
        } else {
            scanf("%d%d", &r, &k);
            q[i].l = 0, q[i].r = r, q[i].k = k;
            h[++all] = k;
        }
    }
    Hash1();
    t[0] = Build(1, size);
    for (int i = 1; i <= n; i++) t[i] = t[0];
    for (int i = 1; i <= n; i++) Add(i, Hash(v[i]), 1);
    for (int i = 1; i <= m; i++) {
        if (q[i].l) {
            printf("%d\n", h[Query(q[i].l, q[i].r, q[i].k)]);
        } else {
            Add(q[i].r, Hash(v[q[i].r]), -1);
            Add(q[i].r, Hash(q[i].k), 1);
            v[q[i].r] = q[i].k;
        }
    }
    return 0;
}