//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        s.erase(startWord);
        while(q.size()!=0)
        {
            pair<string,int>p=q.front();
            string str=p.first;
            int d=p.second;
            q.pop();
            if(str==targetWord)
                return d;
            for(int i=0;i<str.size();i++)
            {
                char origchar=str[i];
                for(char ch='a';ch<='z';ch++)
                {
                    str[i]=ch;
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,d+1});
                    }
                }
                str[i]=origchar;
            }
            s.erase(str);
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends