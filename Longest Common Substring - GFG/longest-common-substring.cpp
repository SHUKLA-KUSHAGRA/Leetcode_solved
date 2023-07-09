//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string str1, string str2, int n, int m)
    {
        // your code here
	    vector<int>prev(m+1,0);
	    vector<int>curr(m+1,0);
	    int maxi=0;
	    for(int i=1;i<=n;i++)
	    {
		    for(int j=1;j<=m;j++)
		    {
			    if(str1[i-1]==str2[j-1])
			    	curr[j] = 1 + prev[j-1]; 
			    else
			    	curr[j] = 0;
			    maxi = max(maxi,curr[j]);
		    }
		    prev=curr;
	    }
	    return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends