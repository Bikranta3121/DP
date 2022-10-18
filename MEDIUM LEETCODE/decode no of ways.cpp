class Solution {
public:
     /****************MEMOIZATION**********************/
    int memoize(int i,string &s,vector<int> &dp)
    {
        if(i<=0) return 1;
        if(dp[i]!=-1) return dp[i];       
        int take=0;
        int take2=0;
        if(s[i]-'0'>0)
        {
          take=memoize(i-1,s,dp);
        }
        
        if((s[i-1]=='2' and s[i]-'0'>=0 and s[i]-'0'<=6)|| (s[i-1]=='1' and s[i]-'0'>=0 and s[i]-'0'<=9))
          take2=memoize(i-2,s,dp);
       
        return dp[i]=take+take2;
    }
  /**************************TABULATION********************************/
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]-'0'==0) return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
           int take=0;
           int take2=0;
           if(s[i-1]>'0') take=dp[i-1];
           if((s[i-2]=='2' and s[i-1]-'0'>=0 and s[i-1]-'0'<=6)|| (s[i-2]=='1' and s[i-1]-'0'>=0 and s[i-1]-'0'<=9)) 
               take2=dp[i-2];
            dp[i]=take+take2;
        }
        return dp[n];
    }
};
