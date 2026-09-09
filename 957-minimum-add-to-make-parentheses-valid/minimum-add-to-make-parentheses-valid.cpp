class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                count++;
            }
            else  {
                if(!st.empty()) {
                    st.pop();
                    count--;
                }
                else {
                    //st.push(s[i]);
                    ans++;
                }
            }
        }
        return (count+ans);
    }
};