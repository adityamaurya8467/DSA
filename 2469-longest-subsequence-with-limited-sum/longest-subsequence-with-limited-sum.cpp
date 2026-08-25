class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        //prefix sum
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        // finding maximum queries
        for(int i = 0; i < m; i++){
            int maxLen = 0;
            int low = 0;
            int high = n-1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] > queries[i]) high = mid-1;
                else{
                    maxLen = mid + 1;
                    low = mid + 1;
                }
            }
            ans[i] = maxLen;
        } 
        return ans;
    }
};