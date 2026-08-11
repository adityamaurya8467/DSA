static const int LIMIT = 1e5;
vector<bool>win(LIMIT + 1, false);
vector<int>square;
auto init = [](){
    for(int i = 1; i <= sqrt(1e5); ++i)
            square.push_back(i * i);
    for(int i = 1; i <= LIMIT; ++i){
        for(int & s : square){
            if(s > i) break;
            if(!win[i - s]){
                win[i] = true;
                break;
            }
        }
    }
    return 0;
}();
class Solution {
public:
    bool winnerSquareGame(int n) {
        return win[n];
    }
};