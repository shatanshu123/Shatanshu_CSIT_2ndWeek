typedef long long ll;
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) 
    {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int m=buses.size(),n=passengers.size();
        ll i=0,j=0,cur=0,ans=1;
        while(i<m&&j<n)
        {
            if(buses[i]>=passengers[j])
            {
                if((j-1>=0)&&(cur<(m-i)*capacity)&&(passengers[j]-1!=passengers[j-1]))ans=passengers[j]-1;
                else if((j==0)&&(cur<(m-i)*capacity))ans=passengers[j]-1;
                j++;
                cur++;
            }else if(buses[i]<passengers[j])
            {
                if(j-1>=0&&cur<capacity&&(buses[i]!=passengers[j-1]))ans=buses[i];
                else if(j==0&&cur<capacity)ans=buses[i];
                cur=max(cur-capacity,0ll);
                i++;
            }
        }
        while(i<m)
        {
            if(cur<capacity&&buses[i]!=passengers.back())ans=buses[i];
            i++;
            cur=max(cur-capacity,0ll);
        }
        return ans;
    }
};