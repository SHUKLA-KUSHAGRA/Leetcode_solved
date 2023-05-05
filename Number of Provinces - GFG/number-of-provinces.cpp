//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findparent(vector<int>& parent,int x){
        if(parent[x]==x)
            return x;
        return parent[x]=findparent(parent,parent[x]);
    }
    void unionbyRank(vector<int>&parent,vector<int>&rank,int x,int y){
        int parx=findparent(parent,x);
        int pary=findparent(parent,y);
        if(parx==pary)
            return;
        else if(rank[parx]<rank[pary])
        {
            parent[parx]=pary;
        }
        else if(rank[pary]<rank[parx])
        {
            parent[pary]=parx;
        }
        else
        {
            parent[pary]=parx;
            rank[pary]++;
        }
        // parx=findparent(parent,x);
        // pary=findparent(parent,y);
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>parent(V);
        vector<int>rank(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                    unionbyRank(parent,rank,i,j);
            }
        }
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends