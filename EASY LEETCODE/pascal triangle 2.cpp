class Solution {
public:
  /*****************************TABULATION***************************************/
    vector<int> getRow(int n) {
        vector<vector<int>> ans(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0 || j==i) ans[i][j]=1;
                else ans[i][j]=ans[i-1][j]+ans[i-1][j-1];                  
            }
        }
        
        vector<int> v;
            for(int j=0;j<=n;j++)
            {
                v.push_back(ans[n][j]);                  
            }
           return v;
    }
};
