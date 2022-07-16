class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int sz=nums.size();
      
        vector<int> left_smaller(sz,-1);
        stack<int> st;
        for(int i=0;i<sz;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i])st.pop();
            if(!st.empty())left_smaller[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        vector<int> right_smaller(sz,sz);
        for(int i=sz-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty())right_smaller[i]=st.top();
           
            st.push(i);
        }
        for(int i=0;i<sz;i++){
            int k=right_smaller[i]-left_smaller[i]-1;
            double val=(double)(threshold)/k;
            if(nums[i]>val)return k;
        }
        return -1;
    }
};