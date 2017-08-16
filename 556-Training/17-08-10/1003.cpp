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
const int N = 100100;
pii ar[N];
int br[N];
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 1, n + 1) {
            cin >> ar[i].first;
            ar[i].second = i;
        }
        sort(ar + 1, ar + n + 1);
        REP(i, 2, n + 1) {
            PER(j, 1, n + 1) {
                if (ar[j].second % i) {
                    br[i] = ar[j].first;
                    break;
                }
            }
        }
        cout << br[2];
        REP(i, 3, n + 1) {
            cout << " " << br[i];
        }
        cout << endl;
    }
    return 0;
}