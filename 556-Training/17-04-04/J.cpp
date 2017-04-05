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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    double a, v1, v2;
    while (cin >> a >> v1 >> v2) {
        if (a == 0) {
            cout << 0 << endl;
            continue;
        }
        if (v1 <= v2) {
            cout << "Infinity" << endl;
            continue;
        }
        cout << fixed << setprecision(10) << a * v1 / (v1 * v1 - v2 * v2) << endl;
    }
    return 0;
}