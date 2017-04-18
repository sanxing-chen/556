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
int c[100005];
int lowbit(int t) {
    return t & -t;
}
int getsum(int x) {
    int temp = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) temp += c[i];
    return temp;
}
void update(int t, int v, int n) {
    for (int i = t; i <= n; i += lowbit(i)) c[i] += v;
}
int a[100005];
int main() {
    ios::sync_with_stdio(false);
    int cas, n, temp, r, l, cnt;
    cin >> cas;
    for (int ca = 1; ca <= cas; ca++) {
        cin >> n;
        mems(c, 0);
        for (int i = 0; i < n; i++) {
            cin >> temp;
            update(temp, 1, n);
            cnt = temp - getsum(temp);
            r = max(i + 1 + cnt, temp);
            l = min(i + 1, temp);
            a[temp] = r - l;
        }
        cout << "Case #" << ca << ": ";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
    }
}