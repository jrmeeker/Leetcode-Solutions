'''You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.'''

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        #find midpoint 
        mid, fast = head, head.next

        while fast and fast.next:
            mid = mid.next
            fast = fast.next.next

        #reverse back half of list 
        node = mid.next
        prev = None
        mid.next = None

        while node:
            next_ = node.next
            node.next = prev
            prev = node
            node = next_

        one, two = head, prev
        while one and two:
            next1, next2 = one.next, two.next
            one.next = two
            two.next = next1
            one, two = next1, next2