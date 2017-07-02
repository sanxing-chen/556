#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define endl "\n"

using namespace std;
typedef long long ll;
const int maxn = 50;
int a[maxn][maxn]; //增广矩阵
int x[maxn];       //解集
bool freeX[maxn];  //标记解是否是自由变元

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
void debug() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 31; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
//高斯消元 mod 2 版
int gauss1(int equ, int var) {
    for (int i = 0; i <= var; i++) {
        x[i] = 0;
        freeX[i] = true;
    }
    //转换为阶梯矩阵
    // col表示当前正在处理的这一列
    int col = 0;
    int row = 0;
    // maxR表示当前这个列中元素绝对值最大的行
    int maxRow;
    for (; row < equ && col < var; row++, col++) {
        //枚举当前正在处理的行
        //找到该col列元素绝对值最大的那行与第k行交换
        maxRow = row;
        for (int i = row + 1; i < equ; i++) {
            if (abs(a[maxRow][col]) < abs(a[i][col])) {
                maxRow = i;
            }
        }
        if (maxRow != row) {
            //与第row行交换
            for (int j = row; j < var + 1; j++) {
                swap(a[row][j], a[maxRow][j]);
            }
        }
        if (a[row][col] == 0) {
            //说明该col列第row行以下全是0，处理当前行的下一列
            row--;
            continue;
        }
        for (int i = row + 1; i < equ; i++) {
            //枚举要删的行
            if (a[i][col] != 0) {
                for (int j = col; j < var + 1; j++) {
                    a[i][j] = a[i][j] ^ a[row][j];
                }
            }
        }
    }
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (int i = var - 1; i >= 0; i--) {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++) {
            if (a[i][j] != 0) {
                x[i] ^= (a[i][j] && x[j]);
            }
        }
    }
    return 0;
}

//高斯消元解方程组
//返回值-2表示有浮点数解，无整数解
//返回值-1表示无解，0表示有唯一解，大于0表示有无穷解，返回自由变元个数
//有equ个方程，var个变元
//增广矩阵行数[0, equ - 1]
//增广矩阵列数[0, var]
int gauss(int equ, int var) {
    for (int i = 0; i <= var; i++) {
        x[i] = 0;
        freeX[i] = true;
    }
    //转换为阶梯矩阵
    // col表示当前正在处理的这一列
    int col = 0;
    int row = 0;
    // maxR表示当前这个列中元素绝对值最大的行
    int maxRow;
    for (; row < equ && col < var; row++, col++) {
        //枚举当前正在处理的行
        //找到该col列元素绝对值最大的那行与第k行交换
        maxRow = row;
        for (int i = row + 1; i < equ; i++) {
            if (abs(a[maxRow][col]) < abs(a[i][col])) {
                maxRow = i;
            }
        }
        if (maxRow != row) {
            //与第row行交换
            for (int j = row; j < var + 1; j++) {
                swap(a[row][j], a[maxRow][j]);
            }
        }
        if (a[row][col] == 0) {
            //说明该col列第row行以下全是0，处理当前行的下一列
            row--;
            continue;
        }
        for (int i = row + 1; i < equ; i++) {
            //枚举要删的行
            if (a[i][col] != 0) {
                int LCM = lcm(abs(a[i][col]), abs(a[row][col]));
                int ta = LCM / abs(a[i][col]);
                int tb = LCM / abs(a[row][col]);
                //异号
                if (a[i][col] * a[row][col] < 0) tb = -tb;
                for (int j = col; j < var + 1; j++) {
                    a[i][j] = a[i][j] * ta - a[row][j] * tb;
                }
            }
        }
    }

    //    //1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (int i = row; i < equ; i++) {
        if (a[i][col] != 0) {
            return -1;
        }
    }

    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    //                  出现的行数即为自由变元的个数.
    if (row < var) {
        // 首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (int i = row - 1; i >= 0; i--) {
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            // freeNum用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            int freeNum = 0;
            int freeIndex = 0;
            for (int j = 0; j < var; j++) {
                if (a[i][j] != 0 && freeX[j]) {
                    freeNum++;
                    freeIndex = j;
                }
            }
            if (1 < freeNum) // 无法求解出确定的变元.
                continue;
            // 说明就只有一个不确定的变元freeIndex，那么可以求解出该变元，且该变元是确定的.
            int tmp = a[i][var];
            for (int j = 0; j < var; j++) {
                if (a[i][j] != 0 && j != freeIndex) {
                    tmp -= a[i][j] * x[j];
                }
            }
            x[freeIndex] = tmp / a[i][freeIndex];
            freeX[freeIndex] = false;
        }
        return var - row;
    }
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (int i = var - 1; i >= 0; i--) {
        int tmp = a[i][var];
        for (int j = i + 1; j < var; j++) {
            if (a[i][j] != 0) {
                tmp -= a[i][j] * x[j];
            }
        }
        if (tmp % a[i][i] != 0) //浮点数
            return -2;
        x[i] = tmp / a[i][i];
    }
    return 0;
}