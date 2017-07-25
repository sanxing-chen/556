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
const int maxn = 10000;
int main() {
    ios::sync_with_stdio(false);
    ll t, n, k, temp;
    int cas = 1;
    while (cin >> n >> k) {
        cout << "Case #" << cas++ << ": ";
        if (k <= n)
            cout << k << endl;
        else {
            k -= n;
            if (k % (n - 1) != 0) {
                cout << (k % (n - 1)) << endl;
            } else {
                temp = k / (n - 1);
                if (temp & 1)
                    cout << n - 1 << endl;
                else
                    cout << n << endl;
            }
        }
    }
    return 0;
}
