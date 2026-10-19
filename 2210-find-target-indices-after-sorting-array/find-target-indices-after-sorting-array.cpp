class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c1 = 0; // starting index
        int c2 = 0; // lenth of ans arr
        for(int i=0;i<nums.size();i++){
            if(nums[i] < target) c1++;
            else if(nums[i] == target) c2++;
        }
        vector<int> ans;
        for(int i=c1;i<(c1 + c2);i++){
            ans.push_back(i);
        }
        return ans;
    }   
};