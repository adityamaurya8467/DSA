class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstmax =  LLONG_MIN;
        long long secondmax =  LLONG_MIN;
        long long thirdmax =  LLONG_MIN;
        for(long long x : nums){
            if(x == firstmax || x == secondmax || x == thirdmax)
            continue;
            if(x > firstmax){
                thirdmax = secondmax;
                secondmax = firstmax;
                firstmax = x;
            }
            else if(x > secondmax){
                thirdmax = secondmax;
                secondmax = x;
            }
            else if(x > thirdmax){
                thirdmax = x;
            }
        }
        if(thirdmax == LLONG_MIN){
            return firstmax;
        }
        else return thirdmax;
    }
};