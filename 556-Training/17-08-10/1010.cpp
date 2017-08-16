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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
vector<int> v[600];
int cnt[600];
bool dfs(int pos) {
    cnt[pos] = 1;
    int temp = 0;
    for (auto to : v[pos]) {
        if (dfs(to)) {
            return true;
        } else {
            cnt[pos] += cnt[to];
            if (cnt[to] & 1) temp++;
        }
    }
    if (temp >= 2) return true;
    if (pos == 1) {
        if (cnt[pos] & 1)
            return true;
        else
            return false;
    }
    if (cnt[pos] & 1) {
        cnt[pos] = 1;
        return false;
    } else {
        cnt[pos] = 0;
        return false;
    }
}
int main() {
#ifdef FUCK
    freopen("1010.in", "r", stdin);
    freopen("my.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int t, temp, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n == 1) {
            cout << "Alice" << endl;
            continue;
        }
        REP(i, 0, n + 1) {
            v[i].clear();
        }
        REP(i, 2, n + 1) {
            cin >> temp;
            v[temp].push_back(i);
        }
        mems(cnt, 0);
        if (dfs(1)) {
            cout << "Alice" << endl;
        } else {
            if (k >= n / 2 - 1)
                cout << "Bob" << endl;
            else
                cout << "Alice" << endl;
        }
    }
    return 0;
}