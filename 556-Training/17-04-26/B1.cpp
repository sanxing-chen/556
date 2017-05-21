#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int main() {
    long long ans, g, f;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            // int i = 2, j = 2;
            cout << i << " " << j << endl;
            ans = 0;
            for (int k = 0; k <= i; k++) {
                ans += j * pow(j - 1, i - k) * abs(j * k - i);
            }
            cout << ans << endl;
            f = pow(j, i + 2);
            g = __gcd(ans, f);
            cout << ans / g << " " << f / g << endl;
            cout << "-----" << endl;
        }
    }
}