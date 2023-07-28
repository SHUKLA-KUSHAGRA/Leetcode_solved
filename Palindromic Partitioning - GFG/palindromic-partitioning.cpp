//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispalindrome(string &str,int i,int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int help(string &str,int i,int j,vector<int>&dp)
    {
        if(i>j)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ways=1e9;
        for(int ind=i;ind<=j;ind++)
        {
            if(ispalindrome(str,i,ind))
            {
                int countways = 1+help(str,ind+1,j,dp);
                ways = min(ways,countways);
            }
        }
        return dp[i] = ways;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n,-1);
        return help(str,0,n-1,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends