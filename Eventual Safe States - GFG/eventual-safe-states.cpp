//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&recst,vector<int>&check)
    {
        vis[node]=1;
        recst[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,recst,check))
                    return true;
            }
            else if(vis[it]==1 && recst[it]==1)
            {
                return true;
            }
        }
        check[node]=1;
        recst[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>recst(V,0);
        vector<int>check(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,recst,check);
            }
        }
        vector<int>res;
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
                res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends