//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int help(int st,int en,vector<int>&a,vector<vector<int>>&dp)
        {
            if(st>en)
                return 0;
            if(dp[st][en]!=-1)
                return dp[st][en];
            int maxi=INT_MIN;
            for (int ind=st;ind<=en;ind++)
            {
                int cost=(a[st - 1]*a[ind]*a[en + 1])+help(st,ind-1,a,dp)
                        +help(ind+1,en,a,dp);
                maxi=max(maxi,cost);
            }
            return dp[st][en] = maxi;
        }
        int maxCoins(int n, vector <int> &arr)
        {
                // write your code here
            vector<int>a(n+2);
            a[0]=1;
            a[n+1]=1;
            for(int i=1;i<=n;i++)
                a[i]=arr[i-1];
            vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            return help(1,n,a,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends