//STRIVER_SDE_SHEET
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>p;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int t=i+1;t<nums.size();t++)
            {
                int j=t+1,k=nums.size()-1;
                 while(j<k)
                 {

                      double sum=(0.0+nums[i]+nums[j]+nums[k]+nums[t]-target);
                    if(sum>0)
                         k--;
                    else if(sum<0)
                        j++;
                    else
                        {
                        p.insert({nums[i],nums[t],nums[j],nums[k]});
                        j++;
                        k--;
                         }
                 }
            }
    }
    vector<vector<int>>ans(p.begin(),p.end());
    return ans;
    }
};