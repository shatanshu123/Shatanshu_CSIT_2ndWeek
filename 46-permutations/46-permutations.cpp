//STRIVER_SDE_SHEET

class Solution {
    private:
    void recurPermute(vector<int> &dfs, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        if(dfs.size()==nums.size()){
            ans.push_back(dfs);
            return;
            
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                dfs.push_back(nums[i]);
                freq[i]=1;
                recurPermute(dfs,nums,ans,freq);
                freq[i]=0;
                dfs.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};