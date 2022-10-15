class Solution {
public:
  
    bool fun(int i,int j,string s,string t)
    {
        if(i<0) return true;
        if(i>=0 and j<0) return false;
        if(s[i]==t[j])
        {
            if(fun(i-1,j-1,s,t)==true) return true;
        }
        else
        {
            if(fun(i,j-1,s,t)==true) return true;
        }   
        return false; 
    }
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        return fun(n-1,m-1,s,t);
        
    }
};
