const int N = 10010;
vector<int> ed[N];
struct LCA {
    int n, rt, bs;
    int deep[N];
    int f[N][20];
    void init(int root, int siz, int base) {
        rt = root, n = siz, bs = base;
        mems(deep, 0);
        mems(f, 0);
        deep[rt] = 1;
        dfs(rt, -1);
        prepare();
    }
    void dfs(int x, int fa) {
        REP(i, 0, ed[x].size()) {
            int &to = ed[x][i];
            if (to == fa) continue;
            deep[to] = deep[x] + 1;
            f[to][0] = x;
            dfs(to, x);
        }
    }

    void prepare() {
        for (int j = 0; j < 17; j++) {
            // begin at bs
            for (int i = bs; i <= n; i++) {
                f[i][j + 1] = f[f[i][j]][j];
            }
        }
    }

    int lca(int x, int y) {
        if (deep[x] < deep[y]) swap(x, y);
        for (int i = 18; i >= 0; i--) {
            if (deep[y] <= deep[f[x][i]]) {
                x = f[x][i];
            }
        }
        if (x == y) return x;
        for (int i = 18; i >= 0; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
} solver;