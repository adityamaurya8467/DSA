class Solution {
public:
    double pow(double x, long long n){
    if(n == 0) return 1;
    double ans = pow(x, n/2);
    if(n % 2 == 0){
        return ans * ans;
    }
    else {
        return ans * ans * x;
    }
}
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            return 1.0 / pow(x, -N);
        }
        return pow(x, N);
    }
};