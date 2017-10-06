//多米诺骨牌完美覆盖，固定宽度，长度极大，使用矩阵快速幂递推
// n = 4 时 0, 1, 1, 5, 11, 36, 95, 281, 781, 2245, 6336, 18061, 51205
// a(n) = a(n-1) + 5*a(n-2) + a(n-3) - a(n-4)
// n = 3 时
// a[n]=4*a[n-2]-a[n-4]
// n = 2 时
// 斐波那契数列
// n = 5 时 1, 8, 95, 1183, 14824, 185921
// b(n) = 15b(n-2) - 32b(n-4) + 15b(n-6) - b(n-8)
// n = 6 时
// a(n) = 40a(n-2) - 416a(n-4) + 1224a(n-6) - 1224a(n-8) + 416a(n-10) - 40a(n-12) + a(n-14)

const int N = 4;
struct Mat {
    int mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = ((ll) c.mat[i][j] + (ll) a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, ll k) {
    Mat c;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) c.mat[i][j] = (i == j);

    for (; k; k >>= 1) {
        if (k & 1) c = c * a;
        a = a * a;
    }
    return c;
}

int K;
int main() {
    Mat _m, _n;
    int temp[4][4] = {{1, 5, 1, -1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    REP(i, 0, 4) REP(j, 0, 4) _m.mat[i][j] = temp[i][j];
    int temp2[4][4] = {{1, 0, 0, 0}, {5, 0, 0, 0}, {11, 0, 0, 0}, {36, 0, 0, 0}};
    REP(i, 0, 4) REP(j, 0, 4) _n.mat[i][j] = temp2[i][j];
    ll N;
    while (read(N)) {
        printf("%lld\n", (((_m ^ (N + 3)) * _n).mat[0][0] + MOD) % MOD);
    }
}