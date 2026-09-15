class Solution {
public:
    bool solve(string &s, int i, int j, int chance){
        if(i >= j) return true;
        if(s[i] == s[j]) return solve(s, i+1, j-1,chance);
        if(chance == 0) return false;
        return solve(s, i + 1, j, 0) ||solve(s, i, j - 1, 0);
    }
    bool validPalindrome(string s) {
        return solve(s,0,s.length()-1,1);
    }
};