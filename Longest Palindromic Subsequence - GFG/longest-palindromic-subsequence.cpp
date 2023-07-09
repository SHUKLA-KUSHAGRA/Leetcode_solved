//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int help(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            dp[i][j]=1+help(i-1,j-1,s,t,dp);
        else
            dp[i][j] = max(help(i-1,j,s,t,dp),help(i,j-1,s,t,dp));
    }
    int longestPalinSubseq(string s) {
        //code here
        string t = s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return help(n-1,n-1,s,t,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends