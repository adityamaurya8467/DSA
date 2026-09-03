class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1 = list1;
        a--;
        while(a--){
            curr1 = curr1->next;
        }
        b++;
        ListNode* curr2 = list1;
        while(b--){
            curr2 = curr2->next;
        }
        ListNode* temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = curr2;
        curr1->next = list2;
        return list1;
    }
};