
const int N = 1000;
struct Matrix {
    long long line, cal;
    long long a[N + 1][N + 1];
    static int M;
    void init() {
        memset(a, 0, sizeof a);
    }
    friend Matrix operator*(Matrix &x, Matrix &s) { //重载／运算符为普通矩阵乘法
        Matrix ans;
        ans.line = x.line, ans.cal = s.cal;
        for (long long i = 0; i < x.line; i++) {
            for (long long j = 0; j < x.cal; j++) {
                for (long long k = 0; k < s.cal; k++) {
                    ans.a[i][j] += x.a[i][k] * s.a[k][j];
                    ans.a[i][j] = (ans.a[i][j] + M) % M;
                }
            }
        }
        return ans;
    }
    template <typename T> friend Matrix operator*(Matrix &x, T &y) {
        Matrix ans;
        for (long long i = 0; i < x.line; i++) {
            for (long long j = 0; j < x.cal; j++) {
                ans.a[i][j] *= y;
            }
        }
        return ans;
    }
    template <typename T> friend Matrix operator^(Matrix &x, T &n) {
        if (n == 1) return x;
        n -= 2;
        long long f = n, ok = 1;
        Matrix ans = x, tmp, ch;
        while (n > 0) {
            if (n % 2) {
                ans = ans * tmp;
            }
            tmp = tmp * tmp;
            n /= 2;
        }
        return ans;
    }
};