//STRIVER_SDE_SHEET

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i, j, k;
        vector<vector<int>> ans;
        if(n < 3) return ans;
        sort(nums.begin(), nums.end());
        
        for (i = 0 ; i < n ; i++) {
                if(i > 0 && nums[i] == nums[i-1]) continue;
                j = i+1;
                k = n-1;
                while(j < k) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                     ans.push_back({nums[i], nums[j], nums[k]});
                     while(j<k && nums[j]==nums[++j]);
                     while(j<k && nums[k]==nums[--k]);
                    }
                    else if(nums[i] + nums[j] + nums[k] > 0)
                        k--;
                    else
                        j++;     
            }
        }
        return ans;
    }
};