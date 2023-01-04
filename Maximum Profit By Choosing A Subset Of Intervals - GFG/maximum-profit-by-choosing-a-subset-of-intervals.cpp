//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // int findnext(int idx,vector<vector<int>>arr)
    // {
    //     int lb=-1;
    //     int l=idx+1;
    //     int h=arr.size()-1;
    //     while(l<=h)
    //     {
    //         int mid=l+(h-l)/2;
    //         if(arr[mid][0]>=arr[idx][1])
    //         {
    //             lb=mid;
    //             h=mid-1;
    //         }
    //         else
    //             l=mid+1;
    //     }
    //     return lb;
    // }
    // int rec(int idx,vector<vector<int>> arr,vector<int>&dp)
    // {
    //     if(idx>=arr.size())
    //         return 0;
    //     if(dp[idx]!=0)
    //         return dp[idx];
    //     int not_select=rec(idx+1,arr,dp);
    //     int nextidx=findnext(idx,arr);
    //     int select=arr[idx][2]+(nextidx==-1 ? 0: rec(nextidx,arr,dp));
    //     return dp[idx]=max(select,not_select);
    // }
    // int maximum_profit(int n, vector<vector<int>> &arr) {
    //     // Write your code here.
    //     sort(arr.begin(),arr.end());
    //     vector<int>dp(n,0);
    //     return rec(0,arr,dp);
    // }
    int getLowerBound(int ind, vector<vector<int>>& arr) {
        int lb = -1;
        int low = ind+1;
        int high = arr.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid][0] >= arr[ind][1]) {
                lb = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return lb;
    }

    int getMaxProfit(int ind, vector<vector<int>>& arr, vector<int>& dp) {
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int notPick = getMaxProfit(ind+1, arr, dp);
        int nextIdx = getLowerBound(ind, arr);

        int pick = arr[ind][2] + (nextIdx == -1 ? 0 : getMaxProfit(nextIdx, arr, dp));

        return dp[ind] = max(pick, notPick);

    }

    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int>dp(n, -1);
        return getMaxProfit(0, intervals, dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends