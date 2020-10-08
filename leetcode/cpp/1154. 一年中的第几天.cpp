#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


bool isLeap(int year)
{
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

int dayOfYear(string date)
{
    int sum = 0;
    int year, month, day;
    sscanf_s(date.data(), "%d-%d-%d", &year, &month, &day);
    const int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31,0 };
    for (int i = 1; i < month; i++) {
        sum += md[i-1];
    }
    sum += day;
    if (month > 2 && isLeap(year)) {
        sum += 1;
    }
    return sum;
}

int main()
{
    cout << dayOfYear("2019-01-09")<<endl; // 9
    cout << dayOfYear("2019-02-10") << endl; // 41
    cout << dayOfYear("2003-03-01") << endl; // 60
    cout << dayOfYear("2004-03-01") << endl; // 61
}
