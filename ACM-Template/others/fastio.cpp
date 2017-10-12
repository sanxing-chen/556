namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline bool read(auto &x) {
    char ch;
    bool ne = false;
    while (blank(ch = nc()))
        ;
    if (IOerror) return false;
    if (ch == '-') ne = true, ch = nc();
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
    if (ne) x = -x;
    return true;
}
#undef BUF_SIZE
};
using namespace fastIO;