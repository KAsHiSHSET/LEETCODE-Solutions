class Solution {
public:
    bool isPalindrome(int x) {
        int ans=0;
        int n=x;

        if(x<0)
            return 0;
        while(n!=0){
            int rem=n%10;
            if(ans<INT_MAX/10)
             ans=rem+ans*10;
            n=n/10;
            }
        
        if(ans==x){
                return 1;
            }
        else
              return 0;

    }
};