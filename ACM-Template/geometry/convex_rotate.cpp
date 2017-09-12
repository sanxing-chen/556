typedef vector<Point> Convex;
#define nxt(x) ((x + 1) % n)
// 排序比较函数，水平序
bool comp_less(Point a, Point b) {
    return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}

// 返回a中点计算出的凸包，结果存在res中
void convex_hull(Convex &res, vector<Point> a) {
    res.resize(2 * a.size() + 5);
    sort(a.begin(), a.end(), comp_less);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = 0;
    for (int i = 0; i < int(a.size()); ++i) {
        while (m > 1 && dcmp((res[m - 1] - res[m - 2]) ^ (a[i] - res[m - 2])) <= 0) --m;
        res[m++] = a[i];
    }
    int k = m;
    for (int i = int(a.size()) - 2; i >= 0; --i) {
        while (m > k && dcmp((res[m - 1] - res[m - 2]) ^ (a[i] - res[m - 2])) <= 0) --m;
        res[m++] = a[i];
    }
    res.resize(m);
    if (a.size() > 1) res.resize(m - 1);
}
// 计算凸包a的直径
double convex_diameter(const Convex &a, int &first, int &second) { // first second表示直径的两个端点
    int n = a.size();
    double ans = 0.0;
    first = second = 0;
    if (n == 1) return ans;
    for (int i = 0, j = 1; i < n; ++i) {
        while (dcmp((a[nxt(i)] - a[i]) ^ (a[j] - a[i]) - (a[nxt(i)] - a[i]) ^ (a[nxt(j)] - a[i])) < 0) j = nxt(j);
        double d = max((a[i] - a[j]).len(), (a[nxt(i)] - a[nxt(j)]).len());
        if (d > ans) ans = d, first = i, second = j;
    }
    return ans;
}