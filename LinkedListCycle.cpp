/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1 && p2){
            if(p1 == p2)
                return true;
            p1 = p1->next;
            if(p2->next)
                p2 = p2->next->next;
            else
                return false;
        }

        return false;
    }
};