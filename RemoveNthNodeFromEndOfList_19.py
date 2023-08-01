'''Given the head of a linked list, remove the nth node from the end of the list and return its head.'''

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if n == 0:
            return head 

        end = head
        i = 0
        while i < n + 1 and end:
            end = end.next
            i += 1

        #node end is now the correct distance ahead of our main node
        node = head
        while end:
            end = end.next
            node = node.next

        if i == n:
            return head.next
        elif node.next:
            node.next = node.next.next
        else:
            head = head.next

        return head
        