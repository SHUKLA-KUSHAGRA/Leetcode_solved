//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(q.size()!=0)
        {
            pair<int,pair<int,int>>p=q.front();
            q.pop();
            int stops=p.first;
            int node=p.second.first;
            int d=p.second.second;
            if(stops>K)
                continue;
            for(auto it:adj[node])
            {
                int v=it.first;
                int w=it.second;
                if(d+w<dist[v] && stops<=K)
                {
                    dist[v]=d+w;
                    q.push({stops+1,{v,d+w}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends