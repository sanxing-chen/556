const int maxnode = 1005 * 25; // 字符串个数 * 字符串长度
const int sigma_size = 26;
struct Trie { //小写字母版
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode]; //可以记录字符串出现的次数
    int sz;           //节点总数
    void init() {
        sz = 1;
        mems(ch[0], 0);
        mems(val, 0);
        mems(cnt, 0);
    }
    int idx(char c) {
        return c - 'a'; //修改这里来改变字符编号规则
    }

    //插入字符串
    void insert(char *s, int v) {
        int u = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) { //节点不存在则创建新节点
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c]; //下一个节点
            cnt[u]++;
        }
        val[u] = v; //串尾附加权值
    }

    void update(char *s, int num) {
        int u = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            u = ch[u][c];
            cnt[u] += num;
        }
    }

    int query(char *s) {
        int u = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            char c = idx(s[i]);
            if (!ch[u][c] || (u != 0 && cnt[u] < 1)) {
                return i; //返回在第几位失配
            }
            u = ch[u][c];
        }
        // return cnt[u];   //查询字符串出现了多少次
        return val[u];
    }
} solver;

// 01字典树，主要修改了树的转移方式
const int maxnode = 1005 * 32;
const int sigma_size = 3;
struct Trie { //小写字母版
    int ch[maxnode][sigma_size];
    ll val[maxnode];
    int cnt[maxnode]; //可以记录字符串出现的次数
    int sz;           //节点总数
    void init() {
        sz = 1;
        mems(ch[0], 0);
        mems(val, 0);
        mems(cnt, 0);
    }

    //插入字符串
    void insert(ll s, int v) {
        int u = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (s & (1LL << i)) > 0;
            if (!ch[u][c]) { //节点不存在则创建新节点
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c]; //下一个节点
            cnt[u]++;
        }
        val[u] = v; //串尾附加权值
    }

    void update(ll s, int num) {
        int u = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (s & (1LL << i)) > 0;
            u = ch[u][c];
            cnt[u] += num;
        }
    }

    int query(ll s) {
        int u = 0;
        for (int i = 32; i >= 0; i--) {
            int c = (s & (1LL << i)) > 0;
            if (ch[u][!c] != 0 && cnt[ch[u][!c]] != 0) {
                u = ch[u][!c];
            } else {
                u = ch[u][c];
            }
        }
        // return cnt[u];   //查询字符串出现了多少次
        return val[u];
    }
} solver;
