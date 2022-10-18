class Solution {
public:
    /*************MEMOIZATION****************************/
    // int memoize(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp)
    // {
    //     if(i==0 and j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(obstacleGrid[i][j]) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left=0;
    //     int up=0;
    //     if(i>0) up=memoize(i-1,j,obstacleGrid,dp);
    //     if(j>0) left=memoize(i,j-1,obstacleGrid,dp);
    //     return dp[i][j]=up+left;
    // }    
    /************************TABULATION******************************/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]) return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]) 
                {
                    dp[i][j]=0;
                    continue;
                }
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
                
            }
        }
       return dp[m-1][n-1]; 
    }
};
