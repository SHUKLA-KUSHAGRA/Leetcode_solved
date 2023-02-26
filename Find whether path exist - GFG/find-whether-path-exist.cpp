//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fx=0,fy=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    break;
                }
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
                        if(nx>=0 && nx<n && ny>=0 && ny<m)
                        {
                            if(grid[nx][ny]==2)
                                return true;
                            else if(grid[nx][ny]==3)
                            {
                                grid[nx][ny]=4;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends