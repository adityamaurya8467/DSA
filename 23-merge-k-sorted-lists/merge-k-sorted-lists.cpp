class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if(list1 == NULL) temp->next = list2;
        else temp->next = list1;
        return c -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1){
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode*  b= lists[0];
            lists.erase(lists.begin());
            ListNode * c = merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};