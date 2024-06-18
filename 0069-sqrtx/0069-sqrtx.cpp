class Solution {
public:
    // 1 2 3 4 5 6 7 8
    // 1 2 3 4 5 6 7 8
    int mySqrt(int x) {
        int low=0;
        int high=x;
        if(x==0||x==1){
            return x;
        }
        while(low<=high){
           long long mid=(low+high)/2;
           long long int vl=mid*mid;
            if(vl==x){
                return mid;
            }
           else if(vl<=x){
             low=mid+1;
            }
            else{
            high=mid-1;
            }
        }
        return high;
    }
};