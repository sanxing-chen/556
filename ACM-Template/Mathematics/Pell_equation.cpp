// 求 x^2-dy^2 = 1的解 d为平方数无解；
const int N = 2;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
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

void search(int &x, int &y, int d) {
    y = 1;
    while (1) {
        x = (long long) sqrt(d * y * y + 1);
        if (x * x - d * y * y == 1) break;
        y++;
    }
}
void solve(int d, int k = 1) { // k为第几个解
    int temp = sqrt(d);
    int xk, yk;
    if (temp * temp == d) {
        cout << "No solution!" << endl;
        return;
    }
    int x, y;
    search(x, y, d);
    Mat m, n, ans;
    m.mat[0][0] = x;
    m.mat[0][1] = d * y;
    m.mat[1][0] = y;
    m.mat[1][1] = x;
    n.mat[0][0] = x;
    n.mat[1][0] = y;
    ans = (m ^ (k - 1)) * n;
    xk = ans.mat[0][0];
    yk = ans.mat[1][0];
}