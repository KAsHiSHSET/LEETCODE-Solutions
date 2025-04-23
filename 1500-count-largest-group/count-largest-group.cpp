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