#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int main() {
    long long ans, g, f, i, j;
    while (cin >> i >> j && i + j) {
        // cout << i << " " << j << endl;
        ans = 0;
        for (int k = 0; k <= i; k++) {
            ans += j * pow(j - 1, i - k) * abs(j * k - i);
        }
        // cout << ans << endl;
        f = pow(j, i + 2);
        g = __gcd(ans, f);
        cout << ans / g << "/" << f / g << endl;
        // cout << "-----" << endl;
    }
}