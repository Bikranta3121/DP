class Solution {
    map<string,vector<int>>dp;
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        
        int s=exp.size();
        for(int i=0;i<s;i++)
        {
            char otr=exp[i];
            if(otr=='+' || otr=='-' || otr=='*')
            {
                vector<int> left,right;
                if(!dp[exp.substr(0,i)].empty()) left=dp[exp.substr(0,i)];
                else left=diffWaysToCompute(exp.substr(0,i));
                 if(!dp[exp.substr(i+1)].empty()) right=dp[exp.substr(i+1)];
                else right=diffWaysToCompute(exp.substr(i+1));
                for(auto itr1:left)
                {
                    for(auto itr2:right)
                    {
                        if(otr=='*')
                         result.push_back(itr1*itr2);
                        if(otr=='+')
                         result.push_back(itr1+itr2);
                        if(otr=='-')
                         result.push_back(itr1-itr2);
                    }
                }
            }
        }
        if(result.empty()) result.push_back(stoi(exp));
        return dp[exp]=result;        
    }
}; 
