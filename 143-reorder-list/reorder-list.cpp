class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!= NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is at the left middle / middle
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow -> next = NULL; 
        // merge these two - a and b alternatively
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA && tempB){
            tempC -> next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            tempC -> next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head = c->next;
    }
};