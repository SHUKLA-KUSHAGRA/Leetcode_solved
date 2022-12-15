//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        // code here
        int x=N;
        int sum=0;
        while(x!=0)
        {
            sum+=x%10;
            x=x/10;
        }
        int st=0;
        int en=0;
        string result="";
        string t="";
        if(N>26)
        {
            t="abcdefghijklmnopqrstuvwxyz";
            int a=N/26;
            N=N%26;
            while(a--)
                result+=t;
        }
        if(N%2==1)
        {
            if(sum%2==0)
            {
                st=(N+1)/2;
                en=(N-1)/2;
            }
            else
            {
                st=(N-1)/2;
                en=(N+1)/2;
            }
        }
        else
        {
            st=N/2;
            en=N/2;
        }
        for(int i=1;i<=st;i++)
                result+=char(96+i);
            for(int i=1;i<=en;i++)
                result+=char(96+26-en+i);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends