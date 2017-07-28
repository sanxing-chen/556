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

int main() {
    ios::sync_with_stdio(false);
    int t, n, x, y;
    string str1, str2;
    cin >> t;
    while (t--) {
        bool flag = false;
        cin >> n >> x >> y;
        cin >> str1 >> str2;
        int cnt = 0;
        REP(i, 0, n) {
            if (str1[i] == str2[i]) cnt++;
        }
        int m = min(min(x, y), cnt);
        x -= m, y -= m;
        if (n - cnt >= x + y) flag = true;
        // cout << cnt << endl;
        cout << (flag ? "Not lying" : "Lying") << endl;
    }
    return 0;
}