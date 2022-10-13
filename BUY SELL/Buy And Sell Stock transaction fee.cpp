#include <bits/stdc++.h> 
// MEOMIZATION
int f(int i,int buy,int fee,vector<int> &prices,vector<vector<int>> dp)
{
    if(i==prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        return dp[i][buy]=max(-fee-prices[i]+f(i+1,0,fee,prices,dp),f(i+1,1,fee,prices,dp));
    }
     return dp[i][buy]= max(prices[i]+f(i+1,1,fee,prices,dp),f(i+1,0,fee,prices,dp)); 
//TABULATION
}
int maximumProfit(int n, int fee, vector<int> &prices) {
   vector<vector<int>> dp(n+1,vector<int>(2,0)); 
   for(int i=n-1;i>=0;i--)
   {
       for(int buy=0;buy<2;buy++)
       {
           if(buy) dp[i][buy]=max(-fee-prices[i]+dp[i+1][0],dp[i+1][1]);
           else dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
       }
   }
    return dp[0][1];
}
