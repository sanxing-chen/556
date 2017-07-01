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

int main() {
    ios::sync_with_stdio(false);
    int n, cnt, t;
    vector<int> v;
    while (cin >> t) {
        cnt = 0;
        while (t--) {
            cin >> n;
            v.clear();
            while (n) {
                v.push_back(n % 4);
                n /= 4;
            }
            for (int i = 0; i < v.size() - 3; i += 4) {
                if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 2 && v[i + 3] == 1) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}