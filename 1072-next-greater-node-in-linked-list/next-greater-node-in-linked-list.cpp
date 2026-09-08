class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n,0);
        nge[n-1] = 0;
        st.push(arr[n-1]);
        for(int i = n-2; i >= 0; i--){
            while(st.size() > 0 && st.top() <= arr[i]){
                st.pop();
            }
            if(st.size() == 0) nge[i] = 0;
            else nge[i] = st.top();
            st.push(arr[i]);
        }
        return nge;
    }
};