class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        multiset<int> right;

        // Elements after index 0
        for (int i = 1; i < n; i++)
            right.insert(nums[i]);

        int leftMin = nums[0];

        for (int j = 1; j < n - 1; j++) {

            // Remove current element from right side
            right.erase(right.find(nums[j]));

            if (nums[j] > leftMin) {

                // First element greater than leftMin
                auto it = right.upper_bound(leftMin);

                if (it != right.end() && *it < nums[j])
                    return true;
            }

            leftMin = min(leftMin, nums[j]);
        }

        return false;
    }
};
