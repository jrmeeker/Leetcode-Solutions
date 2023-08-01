/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

class Solution {
public:
    void reorderList(ListNode* head) {
        //find midpoint
        ListNode* mid = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }

        //midpoint found, reverse back half
        ListNode* node = mid->next;
        ListNode* prev = nullptr;
        
        //disconnect first half
        mid->next = nullptr;

        //reverse back half
        while(node){
            ListNode* next_ = node->next;
            node->next = prev;
            prev = node;
            node = next_;
        }

        //now interleave left and reversed back half
        ListNode* one = head;
        ListNode* two = prev;
        ListNode* next1;
        ListNode* next2;
        while (one && two){
            next1 = one->next, next2 = two->next;
            one->next = two;
            two->next = next1;
            one = next1, two = next2;
        }

    }
};