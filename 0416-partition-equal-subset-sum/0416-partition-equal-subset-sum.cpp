class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total%2)
        return false;
        else{
            int target=total/2;
            vector<vector<int>> dp(n,vector<int> (target+1,0));
            for(int i=0;i<n;i++) dp[i][0]=true;
            if(nums[0]<=target) dp[0][nums[0]]=true;
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=target;j++)
                {
                    bool notTake=dp[i-1][j];
                    bool take=false;
                    if(nums[i]<=j)
                    {
                        take=dp[i-1][j-nums[i]];
                    }
                    dp[i][j]=take | notTake;
                }
                
            }
            return dp[n-1][target];
        }
    }
};