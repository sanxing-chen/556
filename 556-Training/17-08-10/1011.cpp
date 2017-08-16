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
    int t, n;
    cin >> t;
    int a, b, c, ab, ac, bc, abc;
    while (t--) {
        cin >> n;
        int ans = 0;
        REP(i, 0, n) {
            cin >> a >> b >> c >> ab >> bc >> ac >> abc;
            if (a < ab + ac - abc) {
                continue;
            } else if (b < ab + bc - abc) {
                continue;
            } else if (c < bc + ac - abc) {
                continue;
            } else if (ab > a) {
                continue;
            } else if (ac > a) {
                continue;
            } else if (abc > a) {
                continue;
            } else if (ab > b) {
                continue;
            } else if (bc > b) {
                continue;
            } else if (abc > b) {
                continue;
            } else if (ac > c) {
                continue;
            } else if (bc > c) {
                continue;
            } else if (abc > c) {
                continue;
            } else if (abc > ab) {
                continue;
            } else if (abc > bc) {
                continue;
            } else if (abc > ac) {
                continue;
            }

            ans = max(ans, a + b + c - ab - bc - ac + abc);
        }
        cout << ans << endl;
    }
    return 0;
}