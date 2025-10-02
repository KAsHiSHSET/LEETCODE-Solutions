class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;

        if (dividend == INT_MIN && divisor == 1) 
            return INT_MIN;

        if(dividend==divisor) return 1;
        long long int n = llabs((long long)dividend);
        long long int d = llabs((long long)divisor);

        bool sign = (dividend >= 0) == (divisor >= 0);
        long long int ans=0;
        while(n>=d){
            int cnt=0;
            while(n>= (d<<(cnt+1))){
                cnt=cnt+1;
            }
            ans= ans+(1LL<<cnt);
            n=n-(d<<cnt);
        }
       
         return sign? ans:(-ans);
        
    }
};
