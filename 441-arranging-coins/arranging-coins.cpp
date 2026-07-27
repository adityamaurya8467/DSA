class Solution {
public:
    int arrangeCoins(int n) {
        long low = 0, high = n;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long coins = 1LL * mid * (mid + 1) / 2;
            if(coins == n){
                return mid;
            }
            else if(coins < n){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};