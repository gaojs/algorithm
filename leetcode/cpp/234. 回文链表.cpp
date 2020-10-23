#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head) {
    vector<int> a;
    for (; head != nullptr; head = head->next) {
        a.push_back(head->val);
    }
    int n = a.size();
    if (n > 0) {
        for (int i = n / 2; i >= 0; i--) {
            if (a[i] != a[n - i - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
