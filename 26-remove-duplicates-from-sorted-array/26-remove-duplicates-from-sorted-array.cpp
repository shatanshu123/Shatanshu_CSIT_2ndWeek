//STRIVER_SDE_SHEET

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        if(nums.size()==0)
            return 0;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=nums[j]){
                nums[++i]=nums[j++];
            }
            else{
                j++;
            }
        }
        return i+1;
        
    }
};