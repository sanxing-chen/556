#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    double dp[300];
    char o;
    for (int i = 4; i < 100; i++) {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= i; j++) dp[j] = i;
        int cnt = i + 1;
        for (int j = 0; j < i - 1; j++) {
            scanf("%d %c %d", &a, &o, &b);
            if (o == '+')
                dp[cnt++] = dp[a] + dp[b];
            if (o == '-')
                dp[cnt++] = dp[a] - dp[b];
            if (o == '*')
                dp[cnt++] = dp[a] * dp[b];
            if (o == '/')
                dp[cnt++] = dp[a] / dp[b];
        }
        if (dp[cnt - 1] != 24) {
            cout << i << " wrong" << endl;
        }
    }
}