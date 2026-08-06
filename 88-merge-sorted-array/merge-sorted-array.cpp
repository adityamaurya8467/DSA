class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(n + m);
        int i = m-1, j = n-1, k = m+n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                res[k] = nums1[i];
                i--;
            }
            else{
                res[k] = nums2[j];
                j--;
            }
            k--;
        }
            while(i >= 0){
                res[k] = nums1[i];
                k--;
                i--;
            }
            while(j >= 0){
                res[k] = nums2[j];
                k--;
                j--;
            }
        nums1 = res;
    }
};