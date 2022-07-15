//STRIVER_SDE_SHEET

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> tempans;
    
    void helper(vector<int>& candidates, int target, int i, vector<int> tempans, int tempsum){
        
        //base case
        if(i > candidates.size() || tempsum > target)
            return;
        
        if(tempsum == target)
        {
            ans.push_back(tempans);
            return;
        }
        
        //recursive call
        for(int j = i; j < candidates.size(); ++j)
        {
            tempans.push_back(candidates[j]);
            helper(candidates, target, j, tempans, tempsum+candidates[j]);
            tempans.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, tempans, 0);
        return ans;
    }
};