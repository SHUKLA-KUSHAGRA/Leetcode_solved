class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&nums,vector<int>ans,int target,int sum,int idx)
    {
        if(target==sum)
        {
            res.push_back(ans);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])
                continue;
            if(sum+nums[i]<=target)
            {
                sum+=nums[i];
                ans.push_back(nums[i]);
                helper(res,nums,ans,target,sum,i+1);
                sum-=nums[i];
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>ans;
        helper(res,candidates,ans,target,0,0);
        return res;
    }
};