class Solution {
public:
    int tribonacci(int n) {
        int t0=0;
        int t1=1;
        int t2=1;
        for(int i=3;i<=n;i++)
        {
            int temp=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=temp;
        }
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        return t2;
        
    }
};
