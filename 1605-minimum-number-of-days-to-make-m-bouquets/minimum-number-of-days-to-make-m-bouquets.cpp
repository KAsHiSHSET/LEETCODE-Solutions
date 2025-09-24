class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m, int k){
        int cnt=0;
        int total_bloomDay=0;
        for(int i=0;i<bloomDay.size();i++){
             if(bloomDay[i]<=day){
                cnt++;
             }
             else{
                
                total_bloomDay += (cnt/k);
                cnt=0;
             }
        }
        total_bloomDay +=(cnt/k);
        if(total_bloomDay>=m) return true;
        else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int low = mini;
        int high = maxi;
        long long n= bloomDay.size();
        int ans = -1;
        if(n < 1LL * m * k) return ans;
        while(low<=high){
            long long mid = low + (high - low )/2;
            if(possible(bloomDay,mid,m,k)==true){
                 ans=mid;
                 high = mid-1;
            }
            else{
                low= mid+1;
            }
        }

        return ans;

    }
};