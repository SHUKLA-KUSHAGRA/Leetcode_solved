//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(vector<int>&parent,int x)
	{
	    if(parent[x]==x)
	        return parent[x];
	    return parent[x]=find(parent,parent[x]);
	}
	void unionBySize(vector<int>&parent,vector<int>&rank,int x,int y)
	{
	    int parx=find(parent,x);
	    int pary=find(parent,y);
	    if(rank[parx]>rank[pary])
            parent[pary]=parx;
        else if(rank[pary]>rank[parx])
            parent[parx]=pary;
        else
        {
            rank[parx]++;
            parent[pary]=parx;
        }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // KRUSKAL'S ALGORITHM
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                pq.push({it[1],{i,it[0]}});
            }
        }
        vector<int>parent(V);
        vector<int>rank(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        int sum=0;
        while(pq.size()!=0)
        {
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            int wt=p.first;
            int x=p.second.first;
            int y=p.second.second;
            // cout<<wt<<" "<<x<<" "<<y<<endl;
            int parx = find(parent,x);
            int pary = find(parent,y);
            if(parx!=pary)
            {
                sum+=wt;
                unionBySize(parent,rank,x,y);
                parx=find(parent,x);
                pary=find(parent,y);
                // cout<<parx<<" "<<pary<<endl;
            }
        }
        return sum;
        
        // PRIMS ALGORITHM
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // pq.push({0,{0,-1}});
        // int sum=0;
        // vector<int>vis(V,0);
        // while(pq.size()!=0)
        // {
        //     pair<int,pair<int,int>>p=pq.top();
        //     pq.pop();
        //     int node=p.second.first;
        //     int parent=p.second.second;
        //     int weight=p.first;
        //     if(vis[node]==1)
        //         continue;
        //     vis[node]=1;
        //     sum+=weight;
        //     for(auto it:adj[node])
        //     {
        //         int v=it[0];
        //         int w=it[1];
        //         if(vis[v]==0)
        //             pq.push({w,{v,node}});
        //     }
        // }
        // return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends