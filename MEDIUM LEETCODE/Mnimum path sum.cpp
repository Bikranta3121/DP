class Solution {
public:
    /*******************MEMOIZATION***********************/
    int memoize(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i==0 and j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9+7;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=1e9+7;
        int left=1e9+7;
       if(i>0)
           up=grid[i][j]+memoize(i-1,j,dp,grid);
       if(j>0)
           left=grid[i][j]+memoize(i,j-1,dp,grid);
        return dp[i][j]=min(up,left);
    }
    
    /**************TABULATION********************/
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,0));
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0 and j==0) dp[i][j]=grid[i][j];
               else{
               int up=1e9+7;
               int left=1e9+7;
               if(i>0) up=grid[i][j]+dp[i-1][j];
               if(j>0) left=grid[i][j]+dp[i][j-1];
               dp[i][j]=min(up,left);
               }
           }
       }
       return dp[m-1][n-1];
        
    }
};
