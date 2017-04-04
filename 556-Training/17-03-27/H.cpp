#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 313;
const int INF = 0x3f3f3f3f;
#define MAXN 100005
const double PI = acos(-1.0);

struct Complex {
    double real, imag;
    Complex() {}
    Complex(double _real, double _imag)
        : real(_real)
        , imag(_imag) {}
    Complex operator-(const Complex &cp) const {
        return Complex(real - cp.real, imag - cp.imag);
    }
    Complex operator+(const Complex &cp) const {
        return Complex(real + cp.real, imag + cp.imag);
    }
    Complex operator*(const Complex &cp) const {
        return Complex(real * cp.real - imag * cp.imag, real * cp.imag + imag * cp.real);
    }
    void setValue(double _real = 0, double _imag = 0) {
        real = _real;
        imag = _imag;
    }
};

int len;
// Complex wn[MAXN], wn_anti[MAXN];
void FFT(Complex y[], int op, int x) {
    // Rader, 位逆序置换
    len = x;
    for (int i = 1, j = len >> 1, k; i < len - 1; ++i) {
        if (i < j) swap(y[i], y[j]);
        k = len >> 1;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
    // h=1，Wn^0=1
    for (int h = 2; h <= len; h <<= 1) {
        // Wn = e^(2*PI*i/n)，如果是插值Wn = e^(-2*PI*i/n)，i虚数单位
        Complex Wn(cos(-op * 2 * PI / h), sin(-op * 2 * PI / h));
        for (int i = 0; i < len; i += h) {
            Complex W(1, 0);
            for (int j = i; j < i + (h >> 1); ++j) {
                Complex u = y[j], t = W * y[j + (h >> 1)];
                y[j] = u + t;
                y[j + (h >> 1)] = u - t;
                W = W * Wn;
            }
        }
    }
    if (op == -1) {
        for (int i = 0; i < len; ++i) y[i].real /= len;
    }
}
Complex A[1000005], B[1000005];
ll a[500006], f[500006];

long long x, nnn;
void CDQ(ll l, ll r) {
    if (l == r) return;
    ll m = (l + r) / 2;
    CDQ(l, m);
    int k = 1;
    // cout << 'c';
    while (k <= (2 * (r - l + 1))) k *= 2;
    for (int i = 0; i < k; i++) {
        A[i] = (i + l <= m ? Complex(f[i + l], 0) : Complex(0, 0));
        B[i] = (i + 1 <= r - l ? Complex(a[i + 1], 0) : Complex(0, 0));
    }
    FFT(A, 1, k);
    FFT(B, 1, k);
    for (int i = 0; i < k; i++) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1, k);
    // cout << 'b';
    for (int i = m + 1; i <= r; i++) {
        ll y = ((int) (A[i - l - 1].real + 0.5)) % MOD;
        if ((f[i] += y) >= MOD) f[i] -= MOD;
        if (f[i] < 0) f[i] += MOD;
    }
    // cout << 'a';
    CDQ(m + 1, r);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> nnn && nnn) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        //   cout << nnn;
        for (int i = 1; i <= nnn; i++) {
            cin >> x;
            x %= MOD;
            a[i] = x;
        }
        f[0] = 1;
        CDQ(0, nnn);
        cout << (ll) f[nnn] % 313 << "\n";
    }
    return 0;
}