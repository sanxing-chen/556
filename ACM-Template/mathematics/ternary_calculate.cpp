//自己定义f()函数
// Ternary_Calculate(l, r);其中l, r为对应区间的左右端点值
double f(double theta) {
    return blablabla;
}

const double eps = 1e-8;
double Ternary_Calculate(double l, double r) {
    double mid, midmid, ans;
    while (fabs(r - l) > eps) {
        mid = (l + r) / 2;
        midmid = (mid + r) / 2;
        if (f(mid) < f(midmid)) //求极大值
            l = mid;
        else
            r = midmid;
    }
    ans = f(l);
    return ans;
}