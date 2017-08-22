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
const int N = 130000;
int a[N];
multiset<int> st;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl << endl;
            continue;
        }
        REP(i, 0, n) {
            cin >> a[i];
        }
        st.clear();
        v.clear();
        sort(a, a + n);
        REP(i, 0, n) {
            auto pos = st.lower_bound(a[i]);
            if (pos == st.end() || *pos != a[i]) {
                REP(j, 0, v.size()) {
                    st.insert(v[j] + a[i]);
                }
                v.push_back(a[i]);
            } else {
                st.erase(pos);
            }
        }
        cout << v.size() << endl;
        cout << v[0];
        REP(i, 1, v.size()) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}