class Solution {
    int mod=1e9+7;
public:
    /************MEMOIZATION*********/
    // int memoize(int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i==0 and j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=0;
    //     int left=0;
    //    if(i>0)
    //        up=memoize(i-1,j,dp);
    //    if(j>0)
    //        left=memoize(i,j-1,dp);
    //     return dp[i][j]=up+left;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=0;
                int left=0;
                if(i==0 and j==0){ dp[i][j]=1; continue;}
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
     return dp[m-1][n-1];   
    }
};
