class Solution {
public:
int solve(int ind,int a,vector<int> &coins,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(a%coins[0]==0)
        return 1;
        else return 0;
    }
    if(dp[ind][a]!=-1) return dp[ind][a];
    int notPick=solve(ind-1,a,coins,dp);
    int pick=0;
    if(coins[ind]<=a) 
    pick=solve(ind,a-coins[ind],coins,dp);
    return dp[ind][a]=pick+notPick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};