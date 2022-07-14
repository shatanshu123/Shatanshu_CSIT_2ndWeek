//STRIVER_SDE_SHEET

class Solution {
public:
    int m(vector<int>& v, int low, int mid, int high)
    {
        int c = 0, j = mid+1;
        
        //extra part in merge sort for calulating pairs
        //start here
        for(int i=low; i<=mid; i++)
        {
            while(j <= high && v[i] > 2LL*v[j])
                j++;
            c += (j - (mid + 1));
        }
        //ends here
        
        vector<int> t;
        int left = low, right = mid+1;
        while(left <= mid && right <= high)
        {
            if(v[left] <= v[right])
                t.push_back(v[left++]);
            else
                t.push_back(v[right++]);
        }
        while(left <= mid)
            t.push_back(v[left++]);
        while(right <= high)
            t.push_back(v[right++]);
        for(int i=low; i<=high; i++)
        {
            v[i] = t[i-low];
        }
        return c;
    }
    
    int ms(vector<int>& v, int low, int high)
    {
        if(low >= high)
            return 0;
        int mid = (high+low) / 2;
        int c = ms(v, low, mid);
        c += ms(v, mid+1, high);
        c += m(v, low, mid, high);
        return c;
    }
    
    int reversePairs(vector<int>& nums)
    {
        return ms(nums, 0, nums.size()-1);
    }
};