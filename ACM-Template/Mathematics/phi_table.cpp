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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int phi[500000] = {0};
void phi_table(int n) { // table
    for (int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!phi[i]) {
            for (int j = i; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
}
void phi_table2(int n) { //线性筛改
    phi[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; i++) {
        if (!check[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] > n) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

int phi(int x) { // single
    int ret = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ret = ret / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret = ret / x * (x - 1);
    return ret % MOD;
}
int main() {
    int n;
    phi_table(50001 + 2);
    while (scanf("%d", &n) && n != 0) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum += phi[i]; //累加1-n的phi值
        printf("%d\n", sum * 2 - 1);
    }
    return 0;
}