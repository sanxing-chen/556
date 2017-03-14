#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, n, k, l, a[100005];
ll ans;
multiset<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        st.clear();
        cin >> n >> k;
        l = 1, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            while (!st.empty() && (*st.begin() <= a[i] - k || *st.rbegin() >= a[i] + k)) {
                st.erase(st.find(a[l++]));
            }
            st.insert(a[i]);
            ans += i - l + 1;
        }
        cout << ans << "\n";
    }
}