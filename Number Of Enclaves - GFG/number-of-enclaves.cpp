//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int one=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                    q.push({i,j});
                if(grid[i][j]==1)
                    one++;
            }
        }
        while(q.size()!=0)
        {
            pair<int,int>p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            for(int delx=-1;delx<=1;delx++)
            {
                for(int dely=-1;dely<=1;dely++)
                {
                    int nx=x+delx;
                    int ny=y+dely;
                    if(delx==0 || dely==0)
                    {
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && vis[nx][ny]==0)
                        {
                            one--;
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return one;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends