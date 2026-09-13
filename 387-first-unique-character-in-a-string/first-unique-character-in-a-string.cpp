class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            (freq[s[i] - 'a'])++;
        }
        for(int i = 0; i < s.length(); i++){
            if(freq[s[i] - 'a'] == 1) q.push(i);
        }
        if(q.empty()) return -1;
        else return q.front();
    }
};