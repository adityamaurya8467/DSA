//segment n size ka declare karunga taaki baar baaar na karna pade
constexpr int N = 1e5 + 1;
int segment[N] = {0};
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //previous character dummy banaunga kyuki abhi tak value nhi mili h
        char prev = '@';
        int count = 0, active = 0, j = 0;
        for(char & c : s) {
            //active ki value 1 ho to usse badha denge
            active += c == '1';
            //if current value se value change ho to next block me jakar value change kar denge
            j += (prev != c && c == '0');
            segment[j] += c == '0';
            prev = c;
        }
        //create an adjaceny
        int adj = 0;
        //traverse the whole string using loop
        for(int i = 1; i < j; i++) {
            //saare adjency ka current aur uska next adjency ka max nikalunga
            adj = max(adj, segment[i] + segment[i + 1]);
        }
        memset(segment, 0, (j + 1) * sizeof(int));
        return adj + active;
    }
};