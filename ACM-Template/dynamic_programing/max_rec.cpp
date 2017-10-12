// 单调栈法求最大01矩形 O(NM)
const int N = 200;
int n, m, base, a[100005], mps[N][N];
char mp[N][N];
ll l, v, ans;
deque<int> s;
void readMap() {
    for (int i = 1; i <= n; i++) mps[0][i] = 0;
    for (int i = 1; i <= m; i++) {
        getchar();
        for (int j = 1; j <= n; j++) {
            scanf("%c", &mp[i][j]);
            // 0 为可行域
            if (mp[i][j] == '0')
                mps[i][j] = mps[i - 1][j] + 1;
            else
                mps[i][j] = 0;
        }
    }
}
bool solve() {
    if (base > m) return false;
    for (int i = 1; i <= n; i++) {
        a[i] = mps[base][i];
    }
    a[n + 1] = 0, base++;
    return true;
}
int main() {
    while (~scanf("%d%d", &m, &n)) {
        readMap();
        base = 1, ans = 0;
        ll ans2 = 0;
        while (solve()) {
            s.clear();
            s.push_back(0);
            for (int i = 1; i <= n + 1; i++) {
                while (!s.empty() && a[i] < a[s.back()]) {
                    v = a[s.back()];
                    s.pop_back();
                    l = i - s.back() - 1;    //向左拓展下界
                    ans = max(ans, l * v);   // 面积
                    ans2 = max(ans2, l + v); // 半周长
                }
                s.push_back(i);
            }
        }
        printf("%lld\n", ans2 * 2);
    }
}