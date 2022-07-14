//STRIVER_SDE_SHEET

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int>a;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int temp=n/3;
        map<int,bool>visited;
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
               
                if(nums[i]==nums[i+temp] && !visited[nums[i]])
                {
                    a.push_back(nums[i]);
                    visited[nums[i]]=true;
                    i=i+temp;
                }
            }
            
            else if(i==n-1 && nums[i]==nums[i-temp] && !visited[nums[i]])
            { 
                a.push_back(nums[i]);
                break;
            }
            
            else if(i>0 && i<n-temp)
            {
                if((nums[i]==nums[i+temp]) && !visited[nums[i]])
                {
                    a.push_back(nums[i]);
                    visited[nums[i]]=true;
                    i=i+temp;
                }
            }
        }
        
        return a;
    }
};
