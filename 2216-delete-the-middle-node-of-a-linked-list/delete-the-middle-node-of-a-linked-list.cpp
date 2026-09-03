class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != slow){
            prev = curr;
            curr = curr->next;
        }
        prev->next = slow->next;
        return head;


    }
};