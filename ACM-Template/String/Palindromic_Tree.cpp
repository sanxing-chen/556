//先建一个结构体，通过add添加字符，count进行计数

// 1.len[i]表示编号为i的节点表示的回文串的长度（一个节点表示一个回文串）
// 2.next[i][c]表示编号为i的节点表示的回文串在两边添加字符c以后变成的回文串的编号（和字典树类似）。
// 3.fail[i]表示节点i失配以后跳转不等于自身的节点i表示的回文串的最长后缀回文串（和AC自动机类似）。
// 4.cnt[i]表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的）
// 5.num[i]表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数。
// 6.last指向新添加一个字母后所形成的最长回文串表示的节点。
// 7.S[i]表示第i次添加的字符（一开始设S[0] = -1（可以是任意一个在串S中不会出现的字符））。
// 8.p表示添加的节点个数。
// 9.n表示添加的字符个数。
// 全部插入之后，以插入的第i个字符结尾的回文串的个数为num[i+1]，最大长度为len[i+1]，其中i的下标在[1, Len]区间
const int MAXN = 100005;
const int N = 26;

struct Palindromic_Tree {
    int next[MAXN][N]; // next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN]; // fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN];  // cnt[i] 表示第i个节点出现过多少次
    int num[MAXN];
    int len[MAXN]; // len[i]表示节点i表示的回文串的长度
    int S[MAXN];   //存放添加的字符
    int last;      //指向上一个字符所在的节点，方便下一次add
    int n;         //字符数组指针
    int p;         //节点指针

    int newnode(int l) { //新建节点
        for (int i = 0; i < N; ++i) next[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init() { //初始化
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1; //开头放一个字符集中没有的字符，减少特判
        fail[0] = 1;
    }

    int get_fail(int x) { //和KMP一样，失配后找一个尽量最长的
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }

    int add(int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        if (!next[cur][c]) { //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode(len[cur] + 2);          //新建节点
            fail[now] = next[get_fail(fail[cur])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
        return num[last];
    }

    void count() {
        for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
        //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    }
};

// 1.求串S前缀0~i内本质不同回文串的个数（两个串长度不同或者长度相同且至少有一个字符不同便是本质不同）
// 2.求串S内每一个本质不同回文串出现的次数
// 3.求串S内回文串的个数（其实就是1和2结合起来）
// 4.求以下标i结尾的回文串的个数