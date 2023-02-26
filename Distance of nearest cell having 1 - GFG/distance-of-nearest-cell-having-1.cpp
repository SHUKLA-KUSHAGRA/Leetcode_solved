//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>distance(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	                q.push({{i,j},0});
	        }
	    }
	    while(q.size()!=0)
	    {
	        pair<pair<int,int>,int>p=q.front();
	        q.pop();
	        int x=p.first.first;
	        int y=p.first.second;
	        int dis=p.second;
	        for(int delx=-1;delx<=1;delx++)
	        {
	            for(int dely=-1;dely<=1;dely++)
	            {
	                int nx=delx+x;
	                int ny=dely+y;
	                if(delx==0||dely==0)
	                {
	                    if(nx>=0 && nx<n && ny>=0 && ny<m)
	                    {
	                        if(grid[nx][ny]==0 && vis[nx][ny]==0)
	                        {
	                            vis[nx][ny]=1;
	                            distance[nx][ny]=dis+1;
	                            q.push({{nx,ny},dis+1});
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return distance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends