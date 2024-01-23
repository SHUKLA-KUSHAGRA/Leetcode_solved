class Solution {
public:
    int helper(vector<string>& arr,int mask,int idx)
    {
        if(idx==arr.size())
            return 0;
        int take=0;
        int nottake=0;
        bool flag=true;
        int bitmask=mask;
        for(int i=0;i<arr[idx].size();i++)
        {
            if((bitmask&(1<<(arr[idx][i]-'a')))==0)
                bitmask|=(1<<(arr[idx][i]-'a'));
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
            take=arr[idx].size()+helper(arr,bitmask,idx+1);
        nottake=helper(arr,mask,idx+1);
        return max(take,nottake);
    }
    int maxLength(vector<string>& arr) {
        return helper(arr,0,0);
    }
};