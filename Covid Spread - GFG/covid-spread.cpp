//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n=hospital.size();
        int m=hospital[0].size();
        int count=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==2)
                    q.push({{i,j},0});
                if(hospital[i][j]==1)
                    count++;
            }
        }
        int ans=0;
        while(q.size()!=0)
        {
            pair<pair<int,int>,int>p=q.front();
            q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int t=p.second;
            ans=max(ans,t);
            for(int delx=-1;delx<=1;delx++)
            {
                for(int dely=-1;dely<=1;dely++)
                {
                    if(delx==0||dely==0)
                    {
                        int nx=x+delx;
                        int ny=y+dely;
                        if(nx>=0 && nx<n && ny>=0 && ny<m)
                        {
                            if(hospital[nx][ny]==1)
                            {
                                hospital[nx][ny]=2;
                                count--;
                                q.push({{nx,ny},t+1});
                            }
                        }
                    }
                }
            }
        }
        if(count==0)
            return ans;
        return -1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends