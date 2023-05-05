//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int edgesUsed=0;
    int findparent(vector<int>&parent,int x){
        if(parent[x]==x)
            return x;
        return parent[x]=findparent(parent,parent[x]);
    }
    void unionByRank(vector<int>&parent,vector<int>&rank,int x,int y){
        int parx=findparent(parent,x);
        int pary=findparent(parent,y);
        if(parx==pary)
            return;
        if(rank[parx]<rank[pary])
            parent[parx]=pary;
        else if(rank[parx]>rank[pary])
            parent[pary]=parx;
        else
        {
            parent[pary]=parx;
            rank[pary]++;
        }
        edgesUsed++;
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<edge.size();i++)
        {
            unionByRank(parent,rank,edge[i][0],edge[i][1]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                count++;
        }
        if(edge.size()-edgesUsed>=count-1)
            return count-1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends