class Solution {
public:
    int rec(int i,vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]) return dp[i];
        int take=nums[i]+rec(i+2,nums,dp);
        int notake=rec(i+1,nums,dp);
        return dp[i]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            int  take=0;
            int notake=0;
            take=nums[i]+(i+2<=n?dp[i+2]:0);
            notake=dp[i+1];
            dp[i]=max(take,notake);
        }
        return dp[0];
       
    }
};
