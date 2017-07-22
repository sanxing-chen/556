const int N = 110000;
int c[N], n;
int get(int x) {
    int s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
}
void update(int x, int s) {
    for (; x <= n; x += x & -x) c[x] += s;
}