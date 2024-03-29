//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<int>>& visited,vector<vector<char>>grid,int x,int y)
    {
        visited[x][y]=1;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(q.size()!=0)
        {
            pair<int,int>p=q.front();
            q.pop();
            for(int delx=-1;delx<=1;delx++)
            {
                for(int dely=-1;dely<=1;dely++)
                {
                    int nx=p.first+delx;
                    int ny=p.second+dely;
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
                    {
                        if(grid[nx][ny]=='1' && visited[nx][ny]==0)
                        {
                            visited[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    bfs(visited,grid,i,j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends