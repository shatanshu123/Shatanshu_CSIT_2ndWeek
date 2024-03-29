// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
//STRIVER_SDE_SHEET

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job n1,Job n2)
    {
        return n1.profit > n2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> v;
        int m = 0;
        for(int i = 0; i < n; i++){
            m = max(m, arr[i].dead);
        }
    
        bool slots[m];
        fill(slots, slots+m, false);
    
        sort(arr, arr + n, comp);
    
    
        int profit = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            int slot = arr[i].dead - 1;
            if(slots[slot] == false)
            {
                slots[slot] = true;
                count++;
                profit += arr[i].profit;
            }
            else
            {
                while(slot >= 0)
                {
                    if(slots[slot] == false)
                    {
                        slots[slot] = true;
                        count++;
                        profit += arr[i].profit;
                        break;
                    }
                    slot--;
                }
            }
        }
        v.push_back(count);
        v.push_back(profit);
    
        return v;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends