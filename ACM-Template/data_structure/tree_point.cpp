// 树点分治
// num[i] i 的子节点数
// dp[i] 以 i 的子节点为根的最大子树的节点数
int rt, dp[N], vis[N], num[N], tot;
vector<int> g[N];
void dfs(int u, int fa) {
    dp[u] = 0, num[u] = 1;
    REP(i, 0, g[u].size()) {
        int v = g[u][i];
        if (vis[v] || v == fa) continue;
        dfs(v, u);
        dp[u] = max(dp[u], num[v]);
        num[u] += num[v];
    }
    dp[u] = max(dp[u], tot - num[u]);
    if (!~rt || dp[u] < dp[rt]) rt = u;
}
void solve(int u, int deep) {
    rt = -1, tot = num[u];
    dfs(u, u);
    vis[rt] = true;
    u = rt;
    REP(i, 0, g[u].size()) {
        int v = g[u][i];
        if (!vis[v]) solve(v, deep + 1);
    }
}