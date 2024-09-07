class Solution {
public:
    // int solve(int i,vector<int> &coins,int a,vector<vector<int>> &dp)
    // {
    //     if(i==0)
    //     {
    //         if(a%coins[0]==0)
    //         return a/coins[0];
    //         else 
    //         return 1e9;
    //     }
    //     if(dp[i][a]!=-1) return dp[i][a];
    //     int notPick=0+solve(i-1,coins,a,dp);
    //     int pick=1e9;
    //     if(coins[i]<=a)
    //     pick=1+solve(i,coins,a-coins[i],dp);
    //     return dp[i][a]=min(pick,notPick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
        // int res= solve(coins.size()-1,coins,amount,dp);
        // if(amount==0) return 0;
        // if(res>=1e9) return -1;
        // else return res;
        for(int a=0;a<=amount;a++)
        {
            if(a%coins[0]==0)
            dp[0][a]=a/coins[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int a=0;a<=amount;a++)
            {
                int notPick=0+dp[i-1][a];
                int pick=1e9;
                if(coins[i]<=a)
                pick=1+dp[i][a-coins[i]];
                dp[i][a]=min(pick,notPick);
            }
        }
        if(amount ==0 ) return 0;
        if(dp[n-1][amount]>=1e9) return -1;
        else return dp[n-1][amount];

    }
};