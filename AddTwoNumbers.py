'''order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.'''

class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        node = ListNode()
        head = node
        prev = None

        while l1 or l2 or carry:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            res = a + b + carry

            carry = res // 10
            res = res % 10
            node.val = res

            next_node = ListNode()
            node.next = next_node
            
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            prev = node
            node = next_node

        prev.next = None
        return head
        