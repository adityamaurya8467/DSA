class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nsi(n,0);
        // nsi[n-1] = n;
        // st.push(arr[n-1]);
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && st.top() > arr[i]){
                st.pop();
            }
            if(st.size() == 0) nsi[i] = 0;
            else nsi[i] = st.top();
            nsi[i] = arr[i] - nsi[i];
            st.push(arr[i]);
        }
        return nsi;
        
    }
};