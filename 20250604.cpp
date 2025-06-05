#include <vector>
#include <algorithm>
//https://leetcode.com/problems/top-k-frequent-elements/description/
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output; 
        vector<pair<int, int>> m;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int freq = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev) {
                freq++;
            } else {
                m.push_back({prev, freq});
                prev = nums[i];
                freq = 1; 
            }   
        }
        m.push_back({prev, freq});

        sort(m.begin(), m.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k && i < m.size(); i++) {
            output.push_back(m[i].first);
        };
        return output;
    };

};
