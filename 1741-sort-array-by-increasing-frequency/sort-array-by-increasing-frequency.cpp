class Solution {
public:
    typedef pair<int, int> p;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto x : mp){
            pq.push({x.second, -x.first});
        }
        vector<int> ans;
        while(!pq.empty()) {
            int freq = pq.top().first;
            int val = -pq.top().second;
            pq.pop();
            for(int i = 1; i <= freq; i++){
                ans.push_back(val);
            }
        }
        return ans;
    }
};