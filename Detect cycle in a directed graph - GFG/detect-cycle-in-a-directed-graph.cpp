//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFSrec(vector<int> adj[],int s,vector<bool> &recst,vector<bool> &visited)
    {
        visited[s]=true;
        recst[s]=true;
        for(auto it:adj[s])
        {
            if(visited[it]==false)
            {
                if(DFSrec(adj,it,recst,visited)==true)
                    return true;
            }
            else if(recst[it]==true)
                return true;
        }
        recst[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>recst(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(DFSrec(adj,i,recst,visited)==true)
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends