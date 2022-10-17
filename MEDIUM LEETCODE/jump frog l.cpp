class Solution {
public:
    bool memoize(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i==nums.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i+1;j<nums.size() && j<=i+nums[i];j++)
        {
            if(memoize(j,nums,dp)) return dp[j]=true;
        }
         return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        // int n=nums.size();
        // for(int i=n-2;i>=0;i--)
        // {
        //  bool jump=false;   
        //  if(nums[i]==0){
        //      dp[i]=false; 
        //      continue;  
        //  }
        //  if (nums[i] >= n - i - 1){ dp[i]=true;continue;}            
        //  for(int j=i+1;j<nums.size() && j<=i+nums[i];j++)
        //   {
        //     if(j==n-1) jump=jump|dp[j];
        //   }
        //     if(jump) dp[i]=1;
        // }
        return memoize(0,nums,dp);
    }
};
