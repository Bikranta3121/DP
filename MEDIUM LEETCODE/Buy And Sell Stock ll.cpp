class Solution {
public:
    /************memoization***********************/
    int f(int i,int buy,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(i==prices.size())
             return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        return dp[i][buy]=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
            
    }
    /*********************tabulation************************/
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy) dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                    
            }
        }
        return dp[0][1];
    }
};
