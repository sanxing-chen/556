
struct hash {
	struct list {
		long long x; int val; list *next;
	} t[500010], *et, *last[100010];
	hash() { et = t; }
	int &operator[](long long x) {
		int v = abs(x)%99997;
		for(list *it = last[v]; it; it = it->next)
			if(it->x == x) return it->val;
		*++et = (list) {x, 0, last[v]}, last[v] = et;
		return et->val;
	}
}f;