#include <bits/stdc++.h>
using namespace std;

int calc(int a, char op, int b)
{
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

int calculate(string s)
{
    stack<int> nums; // 数值栈
    stack<char> ops; // 符号栈
    int v = 0; // 数值
    for (char e : s) {
        switch (e) {
            case ' ':
                break;
            case '+':
            case '-':
                while (ops.size() > 0) {
                    int a = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    v = calc(a, op, v);
                }
                nums.push(v);
                ops.push(e);
                v = 0;
                break;
            case '*':
            case '/':
                while (ops.size() > 0 &&
                    (ops.top() == '*' || ops.top() == '/')) {
                    int a = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    v = calc(a, op, v);
                }
                nums.push(v);
                ops.push(e);
                v = 0;
                break;
            default: // 数字
                v *= 10;
                v += e - '0';
                break;
        }
    }
    while (ops.size() > 0) {
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        v = calc(a, op, v);
    }
    nums.push(v);
    return nums.top();
}

int main()
{
    // cout << calculate("3+2*2"); // 7
    // cout << calculate(" 3/2 "); // 1
    cout << calculate(" 3+5 / 2 "); // 5
    return 0;
}
