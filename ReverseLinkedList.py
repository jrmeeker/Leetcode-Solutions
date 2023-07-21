#Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head:
            return None 

        prev = None

        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next 

        return prev