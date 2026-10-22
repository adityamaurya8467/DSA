class Solution {
public:
    int minRotations(string s) {
        int curr = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            int target = s[i] - '0';
            int diff = abs(curr - target);
            count += min(diff, 10 - diff);
            curr = target;
        }
        return count;
    }
};