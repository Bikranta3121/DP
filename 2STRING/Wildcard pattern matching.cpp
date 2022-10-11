#include<bits/stdc++.h>
// int f(int i,int j,string &pattern,string &text,vector<vector<int>> &dp)
// {
//     if(i==0 and j==0) return true;
//     if(i==0 and j>0) return false;
//     if(i>0 and j==0)
//     {
//         for(int x=1;x<=i;x++){
//             if(pattern[x-1]!='*') return false;}
//          return true;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
//         return dp[i][j]=f(i-1,j-1,pattern,text,dp);
//     if(pattern[i-1]=='*')
//     {
//         return dp[i][j]=f(i-1,j,pattern,text,dp)|f(i,j-1,pattern,text,dp);
//     }
//     return dp[i][j]=false;
// }

bool wildcardMatching(string pattern, string text)
{
    vector<vector<bool>> dp(pattern.size()+1,vector<bool>          (text.size()+1,false));
    dp[0][0]=true;
    for(int j=1;j<=text.size();j++)
    { dp[0][j]=false;}
    for(int i=1;i<=pattern.size();i++)
    {
        int flag=0;
        for(int x=1;x<=i;x++){
            if(pattern[x-1]!='*') {dp[i][0]=false;flag=1;
                                  break;}
        }
        if(flag==0)
          dp[i][0]=true;
    }
    for(int i=1;i<=pattern.size();i++)
    {
        for(int j=1;j<=text.size();j++)
        {
          if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
            dp[i][j]=dp[i-1][j-1];
    else if(pattern[i-1]=='*')
    {
        dp[i][j]=dp[i-1][j]|dp[i][j-1];
    }
    else dp[i][j]=false;
        }
    }
   return dp[pattern.size()][text.size()];
}
