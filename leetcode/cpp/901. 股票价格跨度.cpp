#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

class StockSpanner {
    vector<int> price;
    stack<int> index;
    int days;

public:
    StockSpanner()
    {
        days = 0;
    }

    int next(int p)
    {
        if (index.size() == 0 || p < price[index.top()]) {
            price.push_back(p);
            index.push(days++);
            return 1;
        }
        int top = index.top();
        while (p >= price[top]) {
            index.pop();
            if (index.empty()) {
                top = -1;
                break;
            }
            top = index.top();
        }
        price.push_back(p);
        index.push(days++);
        return days - top - 1;
    }
};

int main(void)
{
    StockSpanner* obj = new StockSpanner();
    // vector<int> vt = { 100, 80, 60, 70, 60, 75, 85 }; // 1, 1, 1, 2, 1, 4, 6
    vector<int> vt = { 31, 41, 48, 59, 79 }; // 1, 2, 3, 4, 5
    for (int e : vt) {
        cout << obj->next(e) << " ";
    }
    return 0;
}
