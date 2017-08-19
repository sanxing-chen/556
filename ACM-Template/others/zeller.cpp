#include <bits/stdc++.h>
using namespace std;
string weekday[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
int zeller(int year, int month, int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    int c = year / 100;
    year %= 100;
    return ((c / 4 - 2 * c + year + year / 4 + 13 * (month + 1) / 5 + day - 1) % 7 + 7) % 7;
}
int main() {
    int year, month, day;
    while (cin >> year >> month >> day) {
        cout << weekday[zeller(year, month, day)] << endl;
    }
}