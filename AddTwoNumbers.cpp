/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* outHead = new ListNode;
        ListNode* node = outHead;
        int a = 0, b = 0, res = 0, carry = 0;

        while (l1 || l2 || carry){
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            res = a + b + carry;

            carry = res / 10;
            res = res % 10;
            ListNode* nextNode = new ListNode(res);
            node->next = nextNode;

            node = nextNode;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return outHead->next;
    }
};