//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>>&vis,int x,int y,vector<pair<int,int>> &vec,int n,int m,int bx,int by)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1 || vis[x][y]==1)
            return;
        vis[x][y]=1;
        vec.push_back({x-bx,y-by});
        dfs(grid,vis,x,y+1,vec,n,m,bx,by);
        dfs(grid,vis,x+1,y,vec,n,m,bx,by);
        dfs(grid,vis,x,y-1,vec,n,m,bx,by);
        dfs(grid,vis,x-1,y,vec,n,m,bx,by);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>s;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    vector<pair<int,int>>vec;
                    dfs(grid,vis,i,j,vec,n,m,i,j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends