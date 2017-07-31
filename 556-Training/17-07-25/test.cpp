#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
typedef long long ll;
using namespace std;
ll n;
string s[100005];
vector<pii, int> q[27];
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        REP(i, 0, n) {
            cin >> s[i];
        }
    }
    return 0;
}