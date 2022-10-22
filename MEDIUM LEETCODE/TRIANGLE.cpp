class Solution {
public:
    /**********MEMOIZATION******************/
    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
       if(i==triangle.size()-1)
           return triangle[i][j];
       if(dp[i][j]!=10001) return dp[i][j]; 
       return dp[i][j]=triangle[i][j]+min(f(i+1,j,triangle,dp),f(i+1,j+1,triangle,dp)); 
    }
    
    /***********************TABULATION*************************/
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),10001));
        int n=triangle.size();
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
           for(int j=0;j<=i;j++)
           {
               dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
           }
        }
        return dp[0][0];
    }
};
