//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>> &ans,int x,int y,int newC,int prevC)
    {
        if(x<0 || y<0 || x>=ans.size() || y>=ans[0].size() || prevC!=ans[x][y])
            return;
        ans[x][y]=newC;
        dfs(ans,x+1,y,newC,prevC);
        dfs(ans,x,y+1,newC,prevC);
        dfs(ans,x-1,y,newC,prevC);
        dfs(ans,x,y-1,newC,prevC);
    }
    void floodFill(vector<vector<char>>& image, int sr, int sc, char newColor) {
        // Code here 
        char prevColor = image[sr][sc];
        if(newColor==prevColor)
            return;
        dfs(image,sr,sc,newColor,prevColor);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>vis=mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]=='O')
                    vis[i][j]='T';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]=='T')
                floodFill(vis,i,0,'O');
        }
        for(int i=0;i<m;i++)
        {
            if(vis[0][i]=='T')
                floodFill(vis,0,i,'O');
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]=='T')
                floodFill(vis,i,m-1,'O');
        }
        for(int i=0;i<m;i++)
        {
            if(vis[n-1][i]=='T')
                floodFill(vis,n-1,i,'O');
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]=='T')
                    vis[i][j]='X';
            }
        }
        return vis;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends