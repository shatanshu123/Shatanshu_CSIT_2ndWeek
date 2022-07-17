class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0, count1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            count += it.second / 2;
            count1 += it.second % 2;
        }
        return {count, count1};
    }
};