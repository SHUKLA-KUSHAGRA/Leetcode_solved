//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int help(vector<int>&v,int n) {
      stack<int>st;
      int maxA=0;
      for(int i=0;i<=n;i++) {
        while(!st.empty() && (i == n || v[st.top()]>=v[i])) {
          int height=v[st.top()];
          st.pop();
          int width;
          if(st.empty())
            width=i;
          else
            width=i-st.top()-1;
          maxA=max(maxA,width*height);
        }
        st.push(i);
      }
      return maxA;
    }
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>v(m,0);
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
		    for(int j=0;j<m;j++)
		    {
			    if(mat[i][j]==0)
				    v[j]=0;
			    else
				    v[j]=v[j]+1; 
		    }
		    ans=max(ans,help(v,m));
	    }
	    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends