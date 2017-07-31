double F(double x) { //这里自定义函数
    return x * x + x;
}

double simpson(double a, double b) { //返回区间[a,b]的三点辛普森值
    double c = a + (b - a) / 2.0;
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6.0;
}

double asr(double a, double b, double eps, double A) { //自适应辛普森递归过程
    double c = a + (b - a) / 2.0;                      // A为区间[a,b]的三点辛普森值
    double L = simpson(a, c), R = simpson(c, b);
    if (fabs(L + R - A) <= 15 * eps) return L + R + (L + R - A) / 15.0;
    return asr(a, c, eps / 2.0, L) + asr(c, b, eps / 2.0, R);
}

double asr(double a, double b, double eps) { //自适应辛普森主过程
    return asr(a, b, eps, simpson(a, b));
}