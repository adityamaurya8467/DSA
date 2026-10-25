class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> arr;
        while(n > 0){
            int rem = n % 10;
            arr.push_back(rem);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            if((i+1) % 2 != 0) {
                ans += arr[i];
            }
            else{
                ans -= arr[i];
            }
        }
        return ans;
    }
};