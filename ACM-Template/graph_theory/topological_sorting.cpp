const int N = 1010;
priority_queue<int> q;
vector<int> v[N];
int num[N], topo[N], nn, mm;
bool toposort() {
    memset(num, 0, sizeof num);
    cin >> nn >> mm;
    int uu, vv, cnt = 0;
    for (int i = 1; i <= nn; i++) v[i].clear();
    for (int i = 0; i < mm; i++) {
        cin >> uu >> vv;
        v[vv].push_back(uu);
        num[uu]++;
    }
    for (int i = 1; i <= nn; i++)
        if (!num[i]) q.push(i);
    vv = nn;
    while (!q.empty()) {
        uu = q.top();
        q.pop();
        cnt++;
        topo[--vv] = uu;
        for (auto i : v[uu]) {
            num[i]--;
            if (!num[i]) q.push(i);
        }
    }
    if (cnt != nn - 1)
        return false;
    else
        for (int i = 0; i < nn; i++) cout << topo[i] << " \n"[i == nn - 1];
}