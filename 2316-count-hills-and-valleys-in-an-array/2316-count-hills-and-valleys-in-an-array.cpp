class Solution {
public:
    void solve(vector<int> nums, vector<int> &ans)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(ans.empty()||nums[i]!=ans.back())
            ans.push_back(nums[i]);
        }
        
    }
    int countHillValley(vector<int>& nums) {
        vector<int> ans;
        int hills=0,valleys=0;
        solve(nums,ans);
        for(int i=1;i<ans.size()-1;i++)
        {
            if(ans[i]>ans[i-1]&&ans[i]>ans[i+1])
            hills++;
            if(ans[i]<ans[i-1]&&ans[i]<ans[i+1])
            valleys++;
        }
        return hills+valleys;
    }
};