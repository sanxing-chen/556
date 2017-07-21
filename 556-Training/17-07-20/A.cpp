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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 60000;
struct node {
    int a, b;
} sma[maxn], lar[maxn];

bool cmp(node x, node y) {
    return (x.a * log(2.0) + x.b * log(3.0)) > (y.a * log(2.0) + y.b * log(3.0));
}
pii a[maxn], b[maxn];
int aa[maxn], bb[maxn];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, 1, n + 1) {
        cin >> aa[i] >> bb[i];
        a[i] = pii(aa[i], bb[i]);
        b[i] = pii(bb[i], aa[i]);
    }

    sort(aa + 1, aa + n + 1);
    sort(bb + 1, bb + n + 1);
    aa[n + 1] = 1000;
    bb[n + 1] = 1000;
    aa[0] = 0;
    bb[0] = 0;

    int num_min, num_max, pos;
    REP(i, 1, n + 1) {
        pii large = pii(-1, -1), small = pii(-1, -1);
        num_min = i - 1;
        num_max = n - i;
        if (num_min > 1) {
            small.first = aa[1];
            small.second = bb[1];
        } else if (num_min == 0) {
            small.first = aa[n];
            small.second = bb[n];
        } else {
            REP(j, 1, n + 1) {
                pos = upper_bound(aa + 1, aa + n + 1, a[j].first) - (aa + 1);
                sma[j].a = min(a[j].first, aa[pos + 1]);
            }
            REP(j, 1, n + 1) {
                pos = upper_bound(bb + 1, bb + n + 1, b[j].first) - (bb + 1);
                sma[j].b = min(b[j].first, bb[pos + 1]);
            }
            sort(sma + 1, sma + n + 1, cmp);
            small.first = sma[n].a;
            small.second = sma[n].b;
        }

        if (num_max > 1) {
            large.first = aa[n];
            large.second = bb[n];
        } else if (num_max == 0) {
            large.first = aa[1];
            large.second = bb[1];
        } else {
            REP(j, 1, n + 1) {
                pos = lower_bound(aa + 1, aa + n + 1, a[j].first) - 1 - (aa + 1);
                lar[j].a = max(a[j].first, aa[pos + 1]);
            }
            REP(j, 1, n + 1) {
                pos = lower_bound(bb + 1, bb + n + 1, b[j].first) - 1 - (bb + 1);
                lar[j].b = max(b[j].first, bb[pos + 1]);
            }
            sort(lar + 1, lar + n + 1, cmp);
            large.first = lar[1].a;
            large.second = lar[1].b;
        }
        cout << large.first << " " << large.second << " " << small.first << " " << small.second << endl;
    }
    return 0;
}