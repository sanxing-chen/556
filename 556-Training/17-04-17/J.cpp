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
vector<int> a;
int seq[100005];
int lis() {
    int len = 0, pos;
    for (auto i : a) {
        pos = lower_bound(seq, seq + len, i) - seq;
        seq[pos] = i;
        len = max(len, pos + 1);
    }
    return len;
}
int main() {
    ios::sync_with_stdio(false);
#ifdef FF
    freopen("inj", "r", stdin);
    freopen("outj", "w", stdout);
#endif
    int cas, n, temp;
    cin >> cas;
    for (int ca = 1; ca <= cas; ca++) {
        cin >> n;
        a.clear();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (!temp)
                cnt++;
            else
                a.push_back(temp - cnt);
        }
        cout << "Case #" << ca << ": ";
        cout << lis() + cnt << endl;
    }
    return 0;
}