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
long long a[2000000], qt, qc, dc, T, n, db;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n == 2) {
            cout << 2 << "\n";
            continue;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        dc = 1;
        qt = 2;
        for (int i = 1; i < n - 1; i++) {
            if ((a[i] + a[i + 2] - a[i + 1] - a[i + 1]) == 0) {
                qt++;
                continue;
            }
            dc = max(dc, qt);
            qt = 2;
        }
        dc = max(dc, qt);
        db = 1;
        qt = 2;
        for (int i = 1; i < n - 1; i++) {
            if ((a[i] * a[i + 2] - a[i + 1] * a[i + 1]) == 0) {
                qt++;
                continue;
            }
            db = max(db, qt);
            qt = 2;
        }
        db = max(db, qt);
        cout << max(db, dc) << "\n";
    }

    return 0;
}