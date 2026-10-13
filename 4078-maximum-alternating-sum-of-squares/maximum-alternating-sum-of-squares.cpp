class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int  n = nums.size();
        vector<int> ans;
        long long finalans1 = 0;
        long long finalans2 = 0;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < n/2; i++){
            finalans1 -= ans[i];
        }
        for(int i = n/2; i < n; i++){
            finalans2 += ans[i];
        }
        return (finalans1 + finalans2);

    }
};