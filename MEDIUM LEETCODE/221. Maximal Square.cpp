class Solution {
public:
    int func(int i,int j,vector<vector<char>>& matrix,vector<vector<int>> &dp)
    {
      if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0') return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      int right=func(i,j+1,matrix,dp);
      int down=func(i+1,j,matrix,dp);
      int dia=func(i+1,j+1,matrix,dp);
      
      return dp[i][j]=1+min({right,down,dia});
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
      int ans=0;
      int n=matrix.size();
      int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=1;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
          
          for(int j=m-1;j>=0;j--)
          {
            if(matrix[i][j]=='1')
            {
              int dia=0,left=0,up=0;
              if(i<n-1 and j<m-1) dia=dp[i+1][j+1];
              if(i<n-1) up=dp[i+1][j];
              if(j<m-1) left=dp[i][j+1];
              dp[i][j]=1+min({dia,up,left});
              int x=dp[i][j];
              ans=max(ans,x);
            }
          }
        }
        return ans*ans;
    }
};
