class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int deletion = 0;
        int last = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                deletion++;
            }
            else {
                last = nums[i];
            }
        }
        return deletion;
    }
};