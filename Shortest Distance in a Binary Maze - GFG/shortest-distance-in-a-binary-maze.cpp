//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        // DIJKSTRA ALGORITHM
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int sx=source.first;
        int sy=source.second;
        int fx=destination.first;
        int fy=destination.second;
        pq.push({0,{sx,sy}});
        dist[sx][sy]=0;
        while(pq.size()!=0)
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int d=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(x==fx && y==fy)
                return d;
            for(int delx=-1;delx<=1;delx++)
            {
                for(int dely=-1;dely<=1;dely++)
                {
                    int nx=x+delx;
                    int ny=y+dely;
                    if(delx==0 || dely==0)
                    {
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                        {
                            if(dist[x][y]+1<dist[nx][ny])
                            {
                                dist[nx][ny]=dist[x][y]+1;
                                pq.push({d+1,{nx,ny}});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
        // BFS ALGORITHM
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     int X=destination.first;
    //     int Y=destination.second;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     queue<pair<pair<int,int>,int>>q;
    //     q.push({{source.first,source.second},0});
    //     vis[source.first][source.second]=1;
    //     while(q.size()!=0)
    //     {
    //         pair<pair<int,int>,int>p=q.front();
    //         q.pop();
    //         int x=p.first.first;
    //         int y=p.first.second;
    //         int d=p.second;
    //         if(x==X && y==Y)
    //             return d;
    //         for(int delx=-1;delx<=1;delx++)
    //         {
    //             for(int dely=-1;dely<=1;dely++)
    //             {
    //                 int nx=x+delx;
    //                 int ny=y+dely;
    //                 if(delx==0 || dely==0)
    //                 {
    //                     if(nx>=0 && nx<n && ny>=0 && ny<m)
    //                     {
    //                         if(grid[nx][ny]==1 && vis[nx][ny]==0)
    //                         {
    //                             vis[nx][ny]=1;
    //                             q.push({{nx,ny},d+1});
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends