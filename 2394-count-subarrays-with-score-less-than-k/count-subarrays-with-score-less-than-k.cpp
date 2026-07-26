class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long left = 0;
        long long ans = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(left <= right &&
             sum * (right - left + 1LL) >= k){
                sum -= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};