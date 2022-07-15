//STRIVER_SDE_SHEET

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(0,target,candidates,ans,temp);
        return ans;
    }
    void helper(int ind,int target,vector<int>& arr, vector<vector<int>>& ans,vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind==arr.size()) return;
        if(arr[ind]<=target){
            temp.push_back(arr[ind]);
            helper(ind+1,target-arr[ind],arr,ans,temp);
            temp.pop_back();
        }
        while(ind+1<arr.size() && arr[ind]==arr[ind+1]) ind++;
        helper(ind+1,target,arr,ans,temp);
    }
};