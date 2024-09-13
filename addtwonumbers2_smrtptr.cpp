#include <iostream>
#include <memory>

struct ListNode {
    int val;
    std::unique_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, std::unique_ptr<ListNode> next) : val(x), next(std::move(next)) {}
};

class Solution {
public:
    std::unique_ptr<ListNode> addTwoNumbers(std::unique_ptr<ListNode> l1, std::unique_ptr<ListNode> l2) {
        std::unique_ptr<ListNode> dummyHead = std::make_unique<ListNode>(0);
        ListNode* tail = dummyHead.get();
        bool carry = 0;
        int digit1, digit2, digit, sum;

        while (l1 || l2 || carry != 0) {
            digit1 = l1 ? l1->val : 0;
            digit2 = l2 ? l2->val : 0;

            sum = digit1 + digit2 + carry;
            digit = sum % 10;
            carry = sum / 10;

            tail->next = std::make_unique<ListNode>(digit);
            tail = tail->next.get();

            l1 = l1 ? std::move(l1->next) : nullptr;
            l2 = l2 ? std::move(l2->next) : nullptr;
        }

        return std::move(dummyHead->next);
    }
};

int main() {
    auto l1 = std::make_unique<ListNode>(2, std::make_unique<ListNode>(6, std::make_unique<ListNode>(9)));
    auto l2 = std::make_unique<ListNode>(2, std::make_unique<ListNode>(6, std::make_unique<ListNode>(9)));
    Solution sol;
    auto res = sol.addTwoNumbers(std::move(l1), std::move(l2));

    // Print using a temporary pointer
    ListNode* temp = res.get();
    while (temp->next) {
        std::cout << temp->val << ' ';
        temp = temp->next.get();
    }
    std::cout << temp->val << '\n';

    return 0;
}