class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4){
            int ans = 0;
            while(n > 0){
                int last = n % 10;
                ans = ans + last * last;
                n = n/10;

            }
            n = ans;
        }
        if(n == 1){
            return true;
        }
        else {
            return false;
        }
    }
};