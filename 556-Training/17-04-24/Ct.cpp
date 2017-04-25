#include <bits/stdc++.h>
using namespace std;
const int N = 20;
map<vector<int>, int> mp;
int sg(vector<int> v) {
    sort(v.begin(), v.end());
    if (mp.find(v) != mp.end()) return mp[v];
    bool vis[100];
    memset(vis, false, sizeof vis);
    for (int c = 0; c < v.size(); c++) {
        int temp = v[c];
        if (temp > 2) {
            for (int i = 1; i < temp; i++) {
                for (int j = i; j < temp; j++) {
                    for (int k = j; k < temp; k++) {
                        if (i + j + k == temp) {
                            vector<int> _v = v;
                            _v.erase(_v.begin() + c);
                            _v.push_back(i);
                            _v.push_back(j);
                            _v.push_back(k);
                            vis[sg(_v)] = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        vector<int> _v = v;
        _v.erase(_v.begin() + i);
        vis[sg(_v)] = true;
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j < v[i]; j++) {
            v[i] -= j;
            vis[sg(v)] = true;
            v[i] += j;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (vis[i] == false) return mp[v] = i;
    }
}
int main() {
    vector<int> v;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                int ans = 0;
                if (i % 8 == 7)
                    ans ^= 8;
                else if (i % 8 == 0)
                    ans ^= 7;
                else
                    ans ^= i;
                if (j % 8 == 7)
                    ans ^= 8;
                else if (j % 8 == 0)
                    ans ^= 7;
                else
                    ans ^= j;
                if (k % 8 == 7)
                    ans ^= k + 1;
                else if (k % 8 == 0)
                    ans ^= k - 1;
                else
                    ans ^= k;
                v.clear();
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                // cout << i << " " << j << " " << k << endl;
                // cout << (sg(v) ? "first" : "second") << endl;
                // ans = (i % 7) ^ (j % 7) ^ (k % 7);
                // cout << ans << endl;
                // cout << sg(v) << endl;
                if (ans != sg(v)) cout << i << " " << j << " " << k << endl;
            }
        }
    }
}