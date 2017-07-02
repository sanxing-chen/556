bool wzf(int n, int m) {
    if (n > m) swap(n, m);
    int k = m - n;
    int a = (k * (1.0 + sqrt(5.0)) / 2.0);
    if (a == n)
        return false;
    else
        return true;
}