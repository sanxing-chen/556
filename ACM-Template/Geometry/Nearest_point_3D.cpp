#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 4;
struct Point {
    double x;
    double y;
    double z;
};

// [low, high]
int randomInteger(int low, int high) {
    return low + rand() % (high - low + 1);
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

int quickSortPartition(Point *p, int low, int high) {
    int random = randomInteger(low, high);
    swap(p[random], p[low]);
    int i, j;
    i = low, j = high;
    double pivot = p[low].y;
    for (j = low; j <= high; j++) {
        if (pivot > p[j].y) {
            i = i + 1;
            swap(p[i], p[j]);
        }
    }
    swap(p[i], p[low]);
    return i;
}

int partition(double *p, int len, int low, int high) {
    int i, j;
    int random = randomInteger(low, high);
    swap(p[low], p[random]);
    i = low, j = high;
    double pivot = p[low];
    for (j = low; j <= high; j++) {
        if (pivot > p[j]) {
            i = i + 1;
        }
    }
    swap(p[random], p[low]);
    return i;
}

void quickSort(Point *p, int low, int high) {
    if (low < high) {
        int par = quickSortPartition(p, low, high);
        quickSort(p, low, par - 1);
        quickSort(p, par + 1, high);
    }
}

double findMiddle(double *p, int len, int ith) {
    if (len == 1) return p[0];
    int random = partition(p, len, 0, len - 1);
    if (random == ith) {
        return p[random];
    } else if (random < ith) {
        return findMiddle(p + random + 1, len - random - 1, ith - random - 1);
    } else {
        return findMiddle(p, random, ith);
    }
}

double Distance(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

double findMinDistance(Point p[], double arrayX[], double arrayY[], double arrayZ[], int n, Point &des1, Point &des2) {
    double minDistance = INT_MAX;
    if (n <= 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if (Distance(p[i], p[j]) < minDistance) {
                        minDistance = Distance(p[i], p[j]);
                        des1 = p[i], des2 = p[j];
                    }
                }
            }
            return minDistance;
        }
    } else {
        double middleY = findMiddle(arrayY, n, (int) floor((double) (n / 2)));
        // partition P set into PL and PR according to the middle value of y
        Point pL[maxn];
        Point pR[maxn];
        int lIndex = 0, rIndex = 0;
        double leftArrayX[maxn];
        double leftArrayY[maxn];
        double leftArrayZ[maxn];
        double rightArrayX[maxn];
        double rightArrayY[maxn];
        double rightArrayZ[maxn];
        for (int i = 0; i < n; i++) {
            if (p[i].y < middleY) {
                pL[lIndex] = p[i];
                leftArrayX[lIndex] = p[i].x;
                leftArrayY[lIndex] = p[i].y;
                leftArrayZ[lIndex] = p[i].z;
                lIndex++;
            } else {
                pR[rIndex] = p[i];
                rightArrayX[rIndex] = p[i].x;
                rightArrayY[rIndex] = p[i].y;
                rightArrayZ[rIndex] = p[i].z;
                rIndex++;
            }
        }
        // divide and conquer
        double lMinDistance = findMinDistance(pL, leftArrayX, leftArrayY, leftArrayZ, lIndex, des1, des2);
        double rMinDistance = findMinDistance(pR, leftArrayX, leftArrayY, leftArrayZ, rIndex, des1, des2);
        double currentMinDistance = lMinDistance < rMinDistance ? lMinDistance : rMinDistance;
        Point middleP[maxn];
        double middleArrayY[maxn];
        int middleIndex = 0;
        for (int i = 0; i < n; i++) {
            if (fabs(p[i].y - middleY) <= currentMinDistance) {
                middleP[middleIndex] = p[i];
                middleArrayY[middleIndex] = p[i].y;
            }
        }
        for (int i = 0; i < middleIndex; i++) {
            for (int j = 1; j <= 15; j++) {
                if (Distance(p[i], p[i + j]) < currentMinDistance) {
                    currentMinDistance = Distance(p[i], p[i + j]);
                    des1 = p[i];
                    des2 = p[i + j];
                }
            }
        }
        minDistance = currentMinDistance;
        return minDistance;
    }
}

int main() {
    Point p[maxn];
    for (int i = 0; i < maxn; i++) {
        p[i].x = maxn - i;
        p[i].y = maxn - i;
        p[i].z = maxn - i;
    }
    quickSort(p, 0, 3);
    double arrayX[maxn], arrayY[maxn], arrayZ[maxn];
    for (int i = 0; i < maxn; i++) {
        arrayX[i] = p[i].x;
        arrayY[i] = p[i].y;
        arrayZ[i] = p[i].z;
    }
    for (int i = 0; i < maxn; i++) {
        cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
    }
    double minDistance;
    Point des1, des2;
    minDistance = findMinDistance(p, arrayX, arrayY, arrayZ, 4, des1, des2);
    cout << "The minimal distance is:" << minDistance << endl;
    cout << "The two points that have the minimal distance is:" << endl;
    cout << "(" << des1.x << "," << des1.y << "," << des1.z << ")" << endl;
    cout << "(" << des2.x << "," << des2.y << "," << des2.z << ")" << endl;
    getchar();
    return 0;
}
