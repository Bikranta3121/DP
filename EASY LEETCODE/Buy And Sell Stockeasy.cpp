class Solution {
public:
/*********************MEMOIZATION***************************/
// int f(int i,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp)
// {
//     if(cap==0 || i==n) return 0;
//     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
//     if(buy)
//         return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices,n,dp),f(i+1,1,cap,prices,n,dp));
//     else
//         return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices,n,dp),f(i+1,0,cap,prices,n,dp));
// }
    /************************************TABULATION********************************************/
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));  
         // return f(0,1,1,prices,n,dp);
  for(int i=n-1;i>=0;i--)
  {
      for(int j=0;j<=1;j++)
      {
          for(int k=1;k<2;k++)
          {
              if(j) dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
              else dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
              
          }
      }
  }
    return dp[0][1][1];
    }
};
