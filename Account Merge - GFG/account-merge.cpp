//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int findparent(vector<int>& parent,int x){
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
        else if(rank[pary]<rank[parx])
            parent[pary]=parx;
        else
        {
            parent[pary]=parx;
            rank[pary]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        // code here
        unordered_map<string,int>mp;
        vector<int>parent(details.size());
        vector<int>rank(details.size());
        for(int i=0;i<details.size();i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<details.size();i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                if(mp.find(details[i][j])==mp.end())
                    mp[details[i][j]]=i;
                else
                    unionByRank(parent,rank,i,mp[details[i][j]]);
            }
        }
        vector<vector<string>>result;
        vector<string>ansstring[details.size()];
        for(auto it:mp)
        {
            string mail = it.first;
            int node = findparent(parent,it.second);
            ansstring[node].push_back(mail);
        }
        for(int i=0;i<details.size();i++)
        {
            if(ansstring[i].size()==0)
                continue;
            vector<string>temp;
            temp.push_back(details[i][0]);
            sort(ansstring[i].begin(),ansstring[i].end());
            for(auto &it:ansstring[i])
                temp.push_back(it);
            result.push_back(temp);
        }
        sort(result.begin(),result.end(),greater<vector<string>>());
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends