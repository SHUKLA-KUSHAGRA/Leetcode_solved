//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    static void setprime(int n,vector<bool>&prime)
    {
        for(int p=2;p*p<=n;p++) 
        {
            if(prime[p]==true)
            {
                for(int i=p*p;i<=n;i+=p)
                    prime[i]=false;
            }
        }
    }
    int shortestPath(int Num1,int Num2)
    {   
        if(Num1==Num2)
            return 0;
        vector<bool>prime(10000,true);
        setprime(10000,prime);
        // Complete this function using prime vector
        vector<int>ans(10000,-1);
        vector<bool>vis(10000,false);
        queue<int>q;
        q.push(Num1);
        vis[Num1]=false;
        ans[Num1]=0;
        while(q.size()!=0)
        {
            int curr=q.front();
            q.pop();
            if(vis[curr]==true)
                continue;
            string x=to_string(curr);
            for(int i=0;i<4;i++)
            {
                for(char ch='0';ch<='9';ch++)
                {
                    if(ch==x[i] || (ch=='0' && i==0))
                        continue;
                    string y=x.substr(0,i)+ch+x.substr(i+1);
                    int z=stoi(y);
                    if(prime[z] && ans[z]==-1)
                    {
                        ans[z]=1+ans[curr];
                        q.push(z);
                    }
                }
            }
        }
        return ans[Num2];
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends