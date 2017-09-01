const int maxnode = 1005 * 25;
const int sigma_size = 26;
struct Trie { //小写字母版
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode]; //可以记录字符串出现的次数
    int sz;           //节点总数
    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
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

    int query(char s[]) {
        int u = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++) {
            char c = idx(s[i]);
            if (!ch[u][c] || u != 0 && cnt[u] <= 1) {
                return i;
            }
            u = ch[u][c];
        }
        // return cnt[u];   //查询字符串出现了多少次
        return n;
    }
};
int main() {
    int a, b;
    return 0;
}