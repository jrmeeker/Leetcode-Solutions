/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0)
            return head;

        ListNode* end = head;
        int i = 0;
        while (i < n+1 && end){
            end = end->next;
            i++;
        }

        ListNode* node = head;
        while(end){
            node = node->next;
            end = end->next;
        }

        if(i == n)
            return head->next;
        else if (node->next)
            node->next = node->next->next;
        else
            head = head->next;
        return head;
    }
};