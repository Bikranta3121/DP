#include <bits/stdc++.h> 
//MEMOIZATION
int f(int i,int buy,vector<int> &prices,int n,vector<vector<int>> &dp)
{
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
        return dp[i][buy]=max(-            prices[i]+f(i+1,0,prices,n,dp),f(i+1,1,prices,n,dp));
   return dp[i][buy]=max(prices[i]+f(i+2,1,prices,n,dp),f(i+1,0,prices,n,dp));
}

//TABULATION
int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<2;buy++)
        {
            if(buy)
             dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
   else dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
    }
    return dp[0][1];
}
