#include<bits/stdc++.h>
//MEMOIZATION
int f(int i,int prev,int arr[],int n,vector<vector<int>> &dp)
{
    if(i==n) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int len=f(i+1,prev,arr,n,dp);
    if(prev==-1 || arr[i]>arr[prev])
      len=max(len,1+f(i+1,i,arr,n,dp));
    return dp[i][prev+1]=len;
}
//TABULATION
int longestIncreasingSubsequence(int arr[], int n)
{
   vector<vector<int>> dp(n+1,vector<int>(n+1,0)); 
   for(int i=n-1;i>=0;i--)
   {
       for(int prev=i-1;prev>=-1;prev--)
      {
           int len=dp[i+1][prev+1];
           if(prev==-1 || arr[i]>arr[prev])
               len=max(len,1+dp[i+1][i+1]);
           dp[i][prev+1]=len;
       }
   }
    return dp[0][0];
}
