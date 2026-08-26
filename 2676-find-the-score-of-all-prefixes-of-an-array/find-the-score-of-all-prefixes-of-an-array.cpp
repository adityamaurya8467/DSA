class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = 2*nums[0];
        long long mx = nums[0];
        for(int i =1; i < n; i++){
            mx = max(mx,(long long)nums[i]);
            long long ans = nums[i] + mx;
            if(i == 0)
                prefix[i] =  ans;
            else{
                prefix[i] = prefix[i-1] + ans;
            }
            
        }
        return prefix;
    }
};