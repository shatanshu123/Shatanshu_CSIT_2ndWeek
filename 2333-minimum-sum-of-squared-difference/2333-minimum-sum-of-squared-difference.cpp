class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int maxdiff=0;
        for(int i=0;i<n;i++) {
            nums1[i]=abs(nums1[i]-nums2[i]);
            maxdiff=max(maxdiff,nums1[i]);
        }
        vector<int> arr(maxdiff+1,0);
        for(int i=0;i<n;i++) {
            arr[nums1[i]]++;
        }
        k1=k1+k2;
        long long sum=0;
        for(long long i=maxdiff;i>0;i--) {
            if(arr[i]>0){
                if(arr[i]<=k1){
                    k1-=arr[i];
                    arr[i-1]+=arr[i];
                }
                else {
                    arr[i-1]+=k1;
                    sum+=(i*i*(arr[i]-k1));
                    k1=0;
                }
            }
        }
        return sum;
    }
};