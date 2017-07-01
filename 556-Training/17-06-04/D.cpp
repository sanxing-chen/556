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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll a, b;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> a >> b) {
        bool flag = false;
        ll sum, ans, pp, gcd, x1, x2;
        gcd = __gcd(a, b);
        if (a * a - 4 * b * gcd >= 0) {
            flag = true;
            ans = a * a - 4 * b * gcd;
            pp = sqrt(1.0 * a * a - 4.0 * b * gcd);
            if ((pp + a) & 1) flag = false;
            if (pp * pp != ans) flag = false;
            x1 = (a - pp) >> 1;
            x2 = (a + pp) >> 1;
        }
        if (flag)
            cout << x1 << " " << x2 << endl;
        else
            cout << "No Solution" << endl;
    }
    return 0;
}