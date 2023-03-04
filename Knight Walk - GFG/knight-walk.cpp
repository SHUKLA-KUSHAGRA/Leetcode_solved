//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    int gx=KnightPos[0];
	    int gy=KnightPos[1];
	    vis[gx][gy]=1;
	    int fx=TargetPos[0];
	    int fy=TargetPos[1];
	    vis[fx][fy]=1;
	    if(gx==fx && gy==fy)
	        return 0;
	    queue<pair<pair<int,int>,int>>q;
	    int delx[]={2,2,1,-1,-2,-2,1,-1,0};
	    int dely[]={-1,1,2,2,-1,1,-2,-2,0};
	    q.push({{gx,gy},1});
	    while(q.size()!=0)
	    {
	        pair<pair<int,int>,int>p=q.front();
	        q.pop();
	        int x=p.first.first;
	        int y=p.first.second;
	        int d=p.second;
	        for(int i=0;i<8;i++)
	        {
	            int nx=x+delx[i];
	            int ny=y+dely[i];
	            if(nx>0 && nx<=N && ny>0 && ny<=N)
	            {
	                if(vis[nx][ny]==0)
	                {
	                    vis[nx][ny]=1;
	                    q.push({{nx,ny},d+1});
	                }
	                else if(nx==fx && ny==fy)
	                {
	                    return d;
	                }
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends