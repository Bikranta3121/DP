#include<bits/stdc++.h>

//memoization

long buysell(int i,int buy,int n,long *values,vector<vector<long>> &dp){
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    long profit=0;
    if(buy) 
    {
        profit=max(-values[i]+buysell(i+1,0,n,values,dp),buysell(i+1,1,n,values,dp));
    }
    else
       profit=max(values[i]+buysell(i+1,1,n,values,dp),buysell(i+1,0,n,values,dp));
    return dp[i][buy]=profit; 
}

//tabulation

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    dp[n][1]=0;
    dp[n][0]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            long profit=0;
            if(j) 
               profit=max(-values[i]+dp[i+1][0],dp[i+1][1]);
            else
              profit=max(values[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][j]=profit; 
        }
    }
   return dp[0][1]; 
}
