const int MAXN = 2010;
int kN, vN, g[MAXN][MAXN], linker[MAXN];
bool vis[MAXN];
bool dfs(int k) {
    int v;
    for (v = 0; v < vN; v++)
        if (g[k][v] && !vis[v]) {
            vis[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = k;
                return true;
            }
        }
    return false;
}
int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int k = 0; k < kN; k++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(k)) res++;
    }
    return res;
}