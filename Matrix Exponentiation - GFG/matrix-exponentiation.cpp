//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>a,vector<vector<int>>b)
    {
        int mod=1e9+7;
        vector<vector<int>>c(2,vector<int>(2,0));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    c[i][k]=(c[i][k]+(long long)((long long)a[i][j]*(long long)b[j][k]))%mod;
                }
            }
        }
        return c;
    }
    vector<vector<int>> matrix(vector<vector<int>>coeff,int n)
    {
        vector<vector<int>>res={{1,0},{0,1}};
        while(n)
        {
            if(n%2)
                res=multiply(res,coeff);
            coeff = multiply(coeff,coeff);
            n/=2;
        }
        return res;
    }
    int FindNthTerm(long long int n) {
        // Code here
        vector<vector<int>>coeff={{0,1},{1,1}};
        vector<vector<int>>res=matrix(coeff,n);
        return res[1][1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends