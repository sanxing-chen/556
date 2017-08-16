double cross(const Point &p1, const Point &p2, const Point &q1, const Point &q2) {
    return (q2.y - q1.y) * (p2.x - p1.x) - (q2.x - q1.x) * (p2.y - p1.y);
}

bool cmp(const Point &a, const Point &b) {
    Point origin;
    origin.x = origin.y = 0;
    return cross(origin, b, origin, a) < 0;
}
