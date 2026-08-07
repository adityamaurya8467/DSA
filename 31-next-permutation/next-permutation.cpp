class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //1.find pivot elemnt
        int idx = -1;
        for(int i = n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        //2.if array is already greater
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //3.sorting / reverse after pivot
        reverse(nums.begin()+idx+1, nums.end());
        //4.finding the just greater number
        int j = -1;
        for(int i = idx + 1; i < n; i++){
            if(nums[i] > nums[idx]){
                j = i;
                break;
            }
        }
        //5.swapping idx and and j
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;
    }
};