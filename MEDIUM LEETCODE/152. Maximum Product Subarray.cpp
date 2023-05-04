class Solution {
public:
    int func(int i,int prod,vector<int>& nums,map<int,map<int,long long int>> &dp)
    {
       if(i==nums.size()-1) 
       {
           return prod*nums[i];
       }     
       if(dp[prod][i]!=0) return dp[prod][i];
       int take=func(i+1,prod*nums[i],nums,dp);
       int notake=func(i+1,1,nums,dp);
       int max_prod=max({prod*nums[i],take,notake});
       return dp[prod][i]=max_prod;
    }
    int maxProduct(vector<int>& nums) {
        int max_prod=INT_MIN;
        map<int,map<int,long long int>> dp;
        return func(0,1,nums,dp);
        //return max_prod;

    }
};
