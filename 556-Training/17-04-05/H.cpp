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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
pii solve(ll a, ll b, ll c, ll d) {
    // cout << a << " " << b << " " << c << " " << d << endl;
    ll i = (a * d - b * c) * 360, j = b * d;
    // cout << i << " " << j << endl;
    if (i < 0) i = -i;
    ll g = __gcd(i, j);
    i /= g, j /= g;
    return pii(i, j);
}
void print(pii i) {
    if (i.second * 180 < i.first) {
        i.first = i.second * 360 - i.first;
        int g = __gcd(i.second, i.first);
        i.second /= g, i.first /= g;
    }
    if (i.second > 1)
        cout << i.first << "/" << i.second << " ";
    else
        cout << i.first << " ";
}
int main() {
    int t, h, m, s;
    ll h_a, h_b, m_a, m_b, s_a, s_b;
    pii temp;
    cin >> t;
    while (t--) {
        scanf("%2d:%2d:%2d", &h, &m, &s);
        if (h >= 12) h -= 12;
        h_a = m * 60 + s + h * 60 * 60;
        h_b = 60 * 60 * 12;
        m_a = s + m * 60;
        m_b = 60 * 60;
        s_a = s;
        s_b = 60;
        temp = solve(h_a, h_b, m_a, m_b);
        print(temp);
        temp = solve(h_a, h_b, s_a, s_b);
        print(temp);
        temp = solve(m_a, m_b, s_a, s_b);
        print(temp);
        cout << endl;
    }
    return 0;
}