//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(pq.size()!=0)
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int diff=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(x==n-1 && y==m-1)
                return diff;
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
                            int newEffort=max(abs(heights[nx][ny]-heights[x][y]),diff);
                            if(newEffort<dist[nx][ny])
                            {
                                dist[nx][ny]=newEffort;
                                pq.push({newEffort,{nx,ny}});
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends