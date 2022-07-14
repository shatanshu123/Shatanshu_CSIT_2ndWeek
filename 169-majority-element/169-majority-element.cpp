//STRIVER_SDE_SHEET

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(auto t:m){
            if(t.second>n/2) return t.first;
        }
        
        return -1;
    }
};
