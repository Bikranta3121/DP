class Solution {
public:
    /***************KADANE ALGORITHM*************************/
    int maxSubArray(vector<int>& nums) {
        int submax=0;
        int mainmax=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            submax+=nums[i];
            if(submax>mainmax)
            {
                
                mainmax=submax;
            }
            if(submax<0)
                submax=0;
        }
        return mainmax;
        
    }
};
