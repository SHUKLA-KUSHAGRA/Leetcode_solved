//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // void dfs(vector<vector<int>> &ans,int x,int y,int newC,int prevC)
    // {
    //     if(x<0 || y<0 || x>=ans.size() || y>=ans[0].size() || prevC!=ans[x][y])
    //         return;
    //     ans[x][y]=newC;
    //     dfs(ans,x+1,y,newC,prevC);
    //     dfs(ans,x,y+1,newC,prevC);
    //     dfs(ans,x-1,y,newC,prevC);
    //     dfs(ans,x,y-1,newC,prevC);
    // }
    void bfs(vector<vector<int>>&ans,int x,int y,int newC,int prevC,vector<vector<int>>& visited)
    {
        visited[x][y]=1;
        ans[x][y]=newC;
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
                    if(delx==0 || dely==0)
                    {
                        if(nx>=0 && nx<ans.size() && ny>=0 && ny<ans[0].size())
                        {
                            if(ans[nx][ny]==prevC && visited[nx][ny]==0)
                            {
                                q.push({nx,ny});
                                ans[nx][ny]=newC;
                                visited[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int prevColor = image[sr][sc];
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        if(newColor==prevColor)
            return image;
        vector<vector<int>>ans=image;
        // dfs(ans,sr,sc,newColor,prevColor);
        bfs(ans,sr,sc,newColor,prevColor,visited);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends