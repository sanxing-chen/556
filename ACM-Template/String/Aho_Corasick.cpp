//修改string版本只需要将buf变成string类型，并且将insert和query函数中的参数buf改为string类型，下边的strlen改成size即可，
const int maxn = 500010 + 5; //这个大小一般是够的
const int N = 1005;          //匹配串个数
const int SIGMA_SIZE = 26;   // 若是全部字符，修改此处和idx索引函数
struct ACAutomata {
    int nxt[maxn][SIGMA_SIZE]; //节点
    int fail[maxn];            //失配指针
    int end[maxn];             // end[i]记录以i结尾的字符串个数

    int root, L;
    int newnode() {
        for (int i = 0; i < SIGMA_SIZE; i++) nxt[L][i] = -1;
        end[L++] = 0; //计数的时候此处为零，若需要每个结点的信息，此处要改成-1（或者节点的信息从1开始存）
        return L - 1;
    } //建立新节点
    int idx(char ch) {
        return ch - 'a';
    } //获取索引
    void init() {
        L = 0;
        root = newnode();
    }                         //建立根节点
    void insert(char buf[]) { // 若需要存储节点信息，此函数加入参数cnt，并将最后的end[now]的值赋为cnt
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            char ch = idx(buf[i]);
            if (nxt[now][ch] == -1) nxt[now][ch] = newnode();
            now = nxt[now][ch];
        }
        end[now]++;
    }              //建立字典树
    void build() { //建立索引
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < SIGMA_SIZE; i++)
            if (nxt[root][i] == -1)
                nxt[root][i] = root;
            else {
                fail[nxt[root][i]] = root;
                q.push(nxt[root][i]);
            }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < SIGMA_SIZE; i++)
                if (nxt[now][i] == -1) //若该点不存在，直接将该位置指向失配指针的下一位
                    nxt[now][i] = nxt[fail[now]][i];
                else {
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                    q.push(nxt[now][i]);
                }
        }
    }
    int used[N]; // 此数组用于储存某个节点的信息
    int query(char buf[]) {
        int len = strlen(buf);
        int now = root;
        // memset(used, 0, sizeof(used));
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = nxt[now][idx(buf[i])];
            int tmp = now;
            while (tmp != root) {
                // if (end[temp] != -1) {
                //     used[end[temp]]++;
                //     flag = true;
                // } //例：如何存储每个字串出现了几次
                res += end[tmp];
                end[tmp] = 0; //防止重复，如考虑重复情况请注释掉本行，如Hdu5384
                tmp = fail[tmp];
            }
        }
        //可以直接在这里输出used中包含的所有信息
        return res; //返回所有模式串在目标串中出现的总次数
    }
    void Debug() {
        for (int i = 0; i < L; i++) {
            printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
            for (int j = 0; j < SIGMA_SIZE; j++) printf("%2d", nxt[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
ACAutomata ac;
int main() {
    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ac.init();
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("%d\n", ac.query(buf));
    }
    return 0;
}