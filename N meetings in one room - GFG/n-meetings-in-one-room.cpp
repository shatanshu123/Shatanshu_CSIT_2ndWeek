// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
        static  bool helper(pair<int,int>a , pair<int,int> b){ // note static 
        return a.second < b.second;
    }
    


    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end(),helper);
        int count=1,limit=vec[0].second;
        for(int i=1;i<n;i++)
        {
            if( vec[i].first > limit )
            {
                count++;
                limit=vec[i].second;
            }
        }
        return count;
    }
    //STRIVER_SDE_SHEET

};
//STRIVER_SDE_SHEET
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends