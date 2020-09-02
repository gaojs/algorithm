#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

#pragma once
__pragma(once)

struct Test {
    const char *name;
    Test() :name(__func__)
    {
    }
};
int main()
{
    Test t;
    cout << "t.name:" << t.name << endl;
    cout << "__FUNCTION__:" << __FUNCTION__ << endl;
    cout << "__func__:" << __func__ << endl;
    cout << "__LINE__:" << __LINE__ << endl;
    cout << "__FILE__:" << __FILE__ << endl;
    cout << "__DATE__:" << __DATE__ << endl;
    cout << "__TIME__:" << __TIME__ << endl;
    cout << "__STDC_HOSTED__:" << __STDC_HOSTED__ << endl;
    // cout << __STDC_VERSION__ << endl;
    // cout << __STDC__ << endl;
    // cout << __STDC_ISO_10646__ << endl;

#if __cplusplus < 201103L
    cout << "should use C++11" << endl;
    cout << "c++ ver:" << __cplusplus << endl; // 199711
#endif
    // assert(sizeof(int) >= 4);
    static_assert(sizeof(int) >= 4, "error:small int");
    struct init {
        int a = 1;
        double b{ 1.2 };
    };
    init i;
    cout << "init:" << i.a << " " << i.b << endl;
    return 0;
}
