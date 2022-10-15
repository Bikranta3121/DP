class Solution {
public:
    /*******************MEMOIZATION***********************/ 
    int f(int i,vector<int>& cost,vector<int> &dp)
    {
        if(i<=0) return 0;
        if(dp[i]!=-1) return dp[i];
        int first= cost[i]+f(i-1,cost,dp);
        int second=INT_MAX;
        if(i>0)
          second=cost[i-1]+f(i-2,cost,dp);
        return dp[i]=min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return f(n-1,cost,dp);
    }
};
