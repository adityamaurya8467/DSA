class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int flips = 0, i = 0, j = 0;
        int maxLen = 0, len = 0;
        while(j < n){
            if(nums[j] == 1) j++;
            else{  //nums[j] == 0
                if(flips < k){
                    flips++;
                    j++;
                }
                else{ //flips == k
                    //calculate len
                    len = j - i;
                    maxLen = max(maxLen,len);
                    // i ko just uske aage wale 0 se take le jao
                    while(nums[i] == 1) i++;
                    i++;
                    j++;

                }

            }

        }
        len = j - i;
        maxLen = max(maxLen,len);
        return maxLen - 1;
    }
};