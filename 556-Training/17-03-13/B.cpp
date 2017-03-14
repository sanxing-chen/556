#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
#define ll long long
using namespace std;
int mini, maxi;
int t, n, k, a[100005];
priority_queue<pii> q;
priority_queue<pii, vector<pii>, greater<pii>> q2;
int solve1(int i) {
    int re = 0;
    while (!q.empty() && (q.top().first >= a[i] + k || q.top().second < maxi)) {
        maxi = max(maxi, q.top().second);
        re = max(re, q.top().second + 1);
        q.pop();
    }
    maxi = q.top().second;
    mini = i;
    while (!q2.empty() && q2.top().second < mini) q2.pop();
    return re;
}
int solve2(int i) {
    int re = 0;
    while (!q2.empty() && (q2.top().first <= a[i] - k || q2.top().second < mini)) {
        mini = max(mini, q2.top().second);
        re = max(re, q2.top().second + 1);
        q2.pop();
    }
    mini = q2.top().second;
    maxi = i;
    while (!q.empty() && q.top().second < maxi) q.pop();
    return re;
}
int main() {
    ios::sync_with_stdio(false);
    ll ans;
    cin >> t;
    while (t--) {
        while (!q.empty()) q.pop();
        while (!q2.empty()) q2.pop();
        cin >> n >> k;
        ans = 0;
        mini = 1, maxi = 1;
        int re = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            q.push(make_pair(a[i], i));
            q2.push(make_pair(a[i], i));
            if (q.top().first >= a[i] + k) {
                re = solve1(i);
            } else if (q2.top().first <= a[i] - k) {
                re = solve2(i);
            }
            // cout << mini << " " << maxi << endl;
            // cout << re << endl;
            ans += i - re + 1;
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}