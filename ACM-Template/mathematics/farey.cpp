/*
法里级数，在分母不超过 n 的情况下求最贴近 x[0，1] 的有理数，返回最简分数形式
*/
pii farey(ld x, int n) {
    int a = 0, b = 1;
    int c = 1, d = 1;
    while (true) {
        int e = a + c, f = b + d;
        if (f > n) break;
        if (f * x < e) {
            c = e, d = f;
        } else {
            a = e, b = f;
        }
    }
    if (x * d * b - (ld) a * d < (ld) c * b - x * d * b) {
        return pii(a, b);
    } else {
        return pii(c, d);
    }
}