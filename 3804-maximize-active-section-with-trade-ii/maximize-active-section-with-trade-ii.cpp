#include <bits/stdc++.h>
using namespace std;

struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums)
        : n(nums.size()),
          st(std::bit_width((unsigned)max(1, (int)n)), vector<int>(max(1, (int)n))) {

        if (n == 0) return;

        copy(nums.begin(), nums.end(), st[0].begin());

        for (int k = 1; (1 << k) <= n; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = max(st[k - 1][i],
                               st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = std::bit_width((unsigned)(r - l + 1)) - 1;
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries) {

        int ones = ranges::count(s, '1');

        auto [groups, groupId] = getGroups(s);

        if (groups.empty())
            return vector<int>(queries.size(), ones);

        SparseTable st(getMerge(groups));

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int left =
                groupId[l] == -1
                    ? -1
                    : groups[groupId[l]].length -
                          (l - groups[groupId[l]].start);

            int right =
                groupId[r] == -1
                    ? -1
                    : r - groups[groupId[r]].start + 1;

            auto [L, R] =
                mapPair(groupId[l] + 1,
                        s[r] == '1'
                            ? groupId[r]
                            : groupId[r] - 1);

            int best = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                groupId[l] + 1 == groupId[r]) {

                best = max(best, ones + left + right);

            } else if (L <= R) {

                best = max(best,
                           ones + st.query(L, R));
            }

            if (s[l] == '0' &&
                groupId[l] + 1 <=
                    (s[r] == '1'
                         ? groupId[r]
                         : groupId[r] - 1)) {

                best = max(best,
                           ones + left +
                               groups[groupId[l] + 1].length);
            }

            if (s[r] == '0' &&
                groupId[l] < groupId[r] - 1) {

                best = max(best,
                           ones + right +
                               groups[groupId[r] - 1].length);
            }

            ans.push_back(best);
        }

        return ans;
    }

private:
    pair<vector<Group>, vector<int>> getGroups(string& s) {

        vector<Group> groups;
        vector<int> id;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '0') {

                if (i && s[i - 1] == '0')
                    groups.back().length++;
                else
                    groups.push_back({i, 1});
            }

            id.push_back(groups.size() - 1);
        }

        return {groups, id};
    }

    vector<int> getMerge(vector<Group>& groups) {

        vector<int> res;

        for (int i = 0; i + 1 < groups.size(); i++)
            res.push_back(groups[i].length +
                          groups[i + 1].length);

        return res;
    }

    pair<int, int> mapPair(int l, int r) {
        return {l, r - 1};
    }
};