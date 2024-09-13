#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        bool carry = 0;
        int digit1, digit2, sum, digit;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            digit1 = (l1 != nullptr) ? l1->val : 0;
            digit2 = (l2 != nullptr) ? l2->val : 0;

            sum = digit1 + digit2 + carry;
            digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(6, new ListNode(9, nullptr)));
    ListNode* l2 = new ListNode(2, new ListNode(6, new ListNode(9, nullptr)));
    Solution sol;
    ListNode* res = sol.addTwoNumbers(l1, l2);
    while (res->next != nullptr) {
        std::cout << res->val << ' ';
        res = res->next;
    }
    std::cout << res->val << '\n';

    // Free the memory allocated for the result
    while (res != nullptr) {
        ListNode* nextNode = res->next;
        delete res;
        res = nextNode;
    }

        // Free the memory allocated for the input lists
    while (l1 != nullptr) {
        ListNode* nextNode = l1->next;
        delete l1;
        l1 = nextNode;
    }

    while (l2 != nullptr) {
        ListNode* nextNode = l2->next;
        delete l2;
        l2 = nextNode;
    }

    return 0;
}