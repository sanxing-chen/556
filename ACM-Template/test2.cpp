#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
int MOD = 10000;
const int INF = 0x3f3f3f3f;
const int N = 40;
int n, k, m;
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
Mat operator^(Mat a, int k) {
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
Mat operator+(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % MOD;
        }
    }
    return c;
}
Mat cal(Mat a, int l, int r) {
    if (r == l) return a ^ l;
    if ((r - l) % 2 == 1) {
        int d = (r - l - 1) >> 1;
        Mat temp = cal(a, l, l + d);
        return temp + (a ^ (d + 1)) * temp;
    } else {
        int d = (r - l) >> 1;
        Mat temp = cal(a, l, l + d - 1);
        return (a ^ r) + temp + (a ^ d) * temp;
    }
}
int main() {
    Mat a, b, c;
    mems(a.mat, 0);
    mems(b.mat, 0);
    mems(c.mat, 0);
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    MOD = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.mat[i][j];
        }
    }
    b = cal(a, 1, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << b.mat[i][j] << " ";
        }
        cout << b.mat[i][n - 1] << endl;
    }
    return 0;
}