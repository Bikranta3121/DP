class Solution {
public:
    bool f(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int>>> &dp)
    {
        if(i==0 and j==0 and k==0) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i>=1 and k>=1 and s1[i-1]==s3[k-1])
        {
            if(f(i-1,j,k-1,s1,s2,s3,dp)) return dp[i][j][k]=true;
        }
        if(j>=1 and k>=1 and s2[j-1]==s3[k-1])
        {
            if(f(i,j-1,k-1,s1,s2,s3,dp)) return dp[i][j][k]=true; 
        }
        return dp[i][j][k]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int p=s3.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int> (p+1,-1)));
        returnf(n,m,p,s1,s2,s3,dp);
    }
}; 
