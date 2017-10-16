const int N = 10000;
int sg[N], n;
void init() {
    for (int i = 0; i < n; i++) {
        sg[i] = -1;
    }
}
int getSG(int x) {
    if (sg[x] != -1) {
        return sg[x];
    }
    bool vis[N];
    mems(vis, 0);
    for (int i = 0; i < n; i++) { // 遍历所有状态
        if (/*该状态为当前状态的后继状态*/) {
            vis[getSG(i)] = 1;
        }
    }
    for (int i = 0;; i++) {
        if (!vis[i]) {
            sg[x] = i;
            break;
        }
    }
    return sg[x];
}
void print() {
    for (int i = 0; i < n; i++) {
        cout << i << " " << sg[i] << endl;
    }
}
