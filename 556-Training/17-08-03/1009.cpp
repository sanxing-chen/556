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
const int MAXN = 1e6;
int ar[MAXN];
int main() {
    ios::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll cnt = 0;
        REP(i, 0, n) {
            cin >> ar[i];
            if (ar[i] & 1) cnt++;
        }
        if (cnt * 2 >= n) {
            cout << 2 << " " << 1 << endl;
        } else {
            cout << 2 << " " << 0 << endl;
        }
    }
    return 0;
}