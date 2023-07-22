//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comparing(string &s,string &t)
    {
        if(s.size()!=t.size()+1)
            return false;
        int i=0,j=0;
        while(i<s.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else if(s[i]!=t[j])
                i++;
        }
        return i==s.size() && j==t.size();
    }
    static bool cmp(string &s,string &t)
    {
        return s.size()<t.size();
    }
    int longestChain(int n, vector<string>& arr) {
        // Code here
        sort(arr.begin(),arr.end(),cmp);
        int maxi=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(comparing(arr[i],arr[j]) && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends