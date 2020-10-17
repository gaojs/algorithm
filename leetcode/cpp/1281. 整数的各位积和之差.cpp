#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n)
{
    int sum=0, prd=1;
    for (int t = n; t > 0; t = t / 10) {
        int d = t % 10;
        sum += d;
        prd *= d;
    }
    return (prd - sum);
}

int main()
{
    cout << subtractProductAndSum(234)<<endl;
    cout << subtractProductAndSum(4421) << endl;
    return 0;
}