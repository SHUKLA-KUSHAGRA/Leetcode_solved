//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int arr[10]={1,2,5,10,20,50,100,200,500,2000};
        int sum=N;
        vector<int>v;
        for(int i=9;i>=0&&sum>0;i--)
        {
            if(sum-arr[i]>=0)
            {
                int j=sum/arr[i];
                sum=sum%arr[i];
                while(j>0)
                {
                    v.push_back(arr[i]);
                    j--;
                }
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends