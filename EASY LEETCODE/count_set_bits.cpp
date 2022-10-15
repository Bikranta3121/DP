class Solution {
public:
    int count_set_bits(int N)
    {
        int count=0;
        while(N>0)
        {
            count+=(N&1);
            N>>=1;
        }  
        return count;
            
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(count_set_bits(i));
        }
        return ans;
    }
};
