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
bool wzf(int n, int m) {
    if (n > m) swap(n, m);
    int k = m - n;
    int a = (k * (1.0 + sqrt(5.0)) / 2.0);
    if (a == n)
        return 0;
    else
        return 1;
}
int main() {
    ios::sync_with_stdio(false);
    int cas, n, m, ty;
    cin >> cas;
    while (cas--) {
        cin >> ty >> n >> m;
        if (ty == 1) {
            if ((n - 1) % 2 == 0 && (m - 1) % 2 == 0) {
                cout << "G" << endl;
            } else
                cout << "B" << endl;
        } else if (ty == 2) {
            if (n == m)
                cout << "G" << endl;
            else
                cout << "B" << endl;
        } else if (ty == 4) {
            if (wzf(n - 1, m - 1)) {
                cout << "B" << endl;
            } else {
                cout << "G" << endl;
            }
        } else if (ty == 3) {
            n--, m--;
            int n1 = n - 1, m1 = m - 2;
            int n2 = n - 2, m2 = m - 1;
            if ((n1 == m1 && n1 % 3 == 0) || (n2 == m2 && n2 % 3 == 0)) {
                cout << "B" << endl;
            } else if (n == m && n % 3 == 0) {
                cout << "G" << endl;
            } else {
                cout << "D" << endl;
            }
        }
    }
    return 0;
}