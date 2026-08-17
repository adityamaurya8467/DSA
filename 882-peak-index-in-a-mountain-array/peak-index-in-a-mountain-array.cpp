class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        for(int i = 1; i <= n-2; i++){
            if(arr[i] > arr[i-1] && arr[i]>arr[i+1])
            ans = i;
        }
        return ans;
    }
};