class Solution {
public:
  /**********************************TABULATION****************************************************/
   string longestPalindrome(string s) {
        int n=s.size();
        int maxlength=1;
        int x=0;
        int y=0;
        int start_ind=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                maxlength=2;
                start_ind=i;
                dp[i][i+1]=1;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxlength)
                    {
                        maxlength=k;
                        start_ind=i;
                    }    
                }
            }
        }
        string ans="";
        for(int j=start_ind;j<start_ind+maxlength;j++)
        {
            ans+=s[j];
        }
        return ans; 
    }
};
