#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    srand(time(0));
    int n, m, x, y;
    for (int i = 0; i < 100; i++) {
        n = rand();
        m = rand();
        x = rand() * 1.0 / RAND_MAX * n;
        y = rand() * 1.0 / RAND_MAX * m;
        if(x < 1 || y < 1 || n * m <= 1) {
            i--;
            continue;
        } else {
            cout << n << " " << m << " " << x << " " << y << "\n";
        }
    }
}