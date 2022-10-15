class Solution {
public:
  /****************************TABULATION******************************/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows,vector<int>(numRows,0));
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0 || j==i) ans[i][j]=1;
                else ans[i][j]=ans[i-1][j]+ans[i-1][j-1];                  
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++)
        {
            vector<int> v;
            for(int j=0;j<i+1;j++)
            {
                if(ans[i][j]!=0) v.push_back(ans[i][j]);                  
            }
            res.push_back(v);
        }
        return res;
    }
};
