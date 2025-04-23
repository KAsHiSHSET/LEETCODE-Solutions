class Solution {
public:
    int digitsum(int digit){
        int sum=0;
        while(digit){
            int h=digit%10;
            sum+=h;
            digit=digit/10;

        }
        return sum;
    }
    //tc is 0(nlogn)
    //sc is 0(1) as max digit sum can be 36=(9+9+9+9)
 
    //find the sum of all digits, maintain a map 
    //then increase the frequency of the sum of digit we must gave encountered,then find the maximum no 
    //then find for maximum of the frequency how many such digits exists.
    int countLargestGroup(int n) {
        //1->13
        int maxi=0;
        int count=0;
        unordered_map<int,int> mpp;
        for(int i=1;i<=n;i++){
            int sum=digitsum(i);
            mpp[sum]++;
            maxi=max(maxi,mpp[sum]);
        }
        for(auto p:mpp){
            if(p.second==maxi) count++;
        }
        return count;

    }
};