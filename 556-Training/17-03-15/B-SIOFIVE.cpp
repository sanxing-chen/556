// http://siofive.github.io/2015/07/29/hdu5301/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define pb push_back
#define debug puts("=====================");
using namespace std;
int n, m, x, y;
int main() {
    while (~scanf("%d%d%d%d", &n, &m, &x, &y)) {
        if (n > m) swap(n, m), swap(x, y);
        int t = (n + 1) / 2;
        int up = x - 1;
        int dw = n - x;
        int lf = y;
        int rg = m - y + 1;
        if (min(lf, rg) > t && up != dw) t = min(max(up, dw), min(lf, rg));
        if ((n == m) && (n % 2 == 1) && (x == y) && (x * 2 - 1 == n)) t = n / 2;
        printf("%d\n", t);
    }
    return 0;
}