class Solution {
public:
    bool chk(string s)
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                 st.push('(');
            else if(!st.empty()  and s[i]==')' and st.top()=='(')
                st.pop();
            else st.push(')');
        }
        if(st.size()>0) return false;
        return true;
        
    }    
    void func(int i,int j,string ans, vector<string> &res)//RECURSION ADN BACTRACKING
    {
        if(i==0 and j==0)
        {
            if(chk(ans))
                res.push_back(ans);
            return;
        }
        if(i>0)
        {
            ans.push_back('(');
            func(i-1,j,ans,res);
            ans.pop_back();
        }
        
        if(j>0)
        {
            ans.push_back(')');
            func(i,j-1,ans,res);
            ans.pop_back();
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> res;
        func(n,n,ans,res);
        return res;
    }
};
