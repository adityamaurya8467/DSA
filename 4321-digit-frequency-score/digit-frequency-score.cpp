class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        int sum = 0;
        while(n > 0){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
};