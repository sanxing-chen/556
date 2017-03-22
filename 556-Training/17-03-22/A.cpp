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
bool c[20] = {0};
int f[100000] = {0};
int T, a, b;
bool is(int n) {
    memset(c, 0, sizeof(c));
    while (n > 0) {
        if (!c[n % 10]) {
            c[n % 10] = true;
            n /= 10;
        } else
            return false;
    }
    return true;
}
void table() {
    f[0] = 0;
    for (int i = 1; i <= 100000; i++)
        if (is(i))
            f[i] = f[i - 1] + 1;
        else
            f[i] = f[i - 1];
}
int main() {
    cin >> T;
    table();
    while (T--) {
        cin >> a >> b;
        cout << f[b] - f[a - 1] << "\n";
    }
    return 0;
}