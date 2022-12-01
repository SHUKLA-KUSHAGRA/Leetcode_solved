//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int result=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='-' && i==0)
                continue;
            if(str[i]>='0' && str[i]<='9')
                result=result*10+str[i]-'0';
            else
                return -1;
        }
        if(str[0]=='-')
            return 0-result;
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends